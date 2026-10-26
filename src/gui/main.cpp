#include "raylib.h"

#include "Tarot.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <chrono>

static Tarot tarot;

// ---------- estado ----------
enum Screen { SCR_MENU, SCR_TEMA, SCR_PERGUNTA, SCR_RESULTADO,
              SCR_HISTORICO, SCR_BUSCAR, SCR_BUSCAR_RES, SCR_LISTAR };
static Screen current = SCR_MENU;

static int temaEscolhido = 0;
static char perguntaBuf[256] = "";
static int perguntaLen = 0;
static char buscaBuf[256] = "";
static int buscaLen = 0;
static const Carta* cartaBuscada = nullptr;
static std::string statusMsg;
static bool fechar = false;

// ---------- paleta Frutiger Aero ----------
static const Color COL_BG_TOP     = { 135, 206, 250, 255 }; // sky blue
static const Color COL_BG_BOTTOM = { 224, 255, 255, 255 }; // light cyan
static const Color COL_PANEL      = { 255, 255, 255, 170 }; // glass
static const Color COL_BTN        = {  70, 160, 210, 255 }; // aqua
static const Color COL_BTN_HOVER  = { 110, 190, 235, 255 };
static const Color COL_BTN_SHINE  = { 255, 255, 255, 110 };
static const Color COL_BORDER     = { 180, 220, 245, 255 };
static const Color COL_TEXT       = {  30,  60,  90, 255 };
static const Color COL_TITLE      = {   0,  80, 160, 255 };
static const Color COL_ACCENT     = {  60, 180, 120, 255 }; // green

// bolhas decorativas (posicao x, y, raio)
static const int BUBBLE_COUNT = 24;
static const int bubX[BUBBLE_COUNT] = { 60, 740, 120, 680, 400, 200, 600, 300, 520, 150, 650, 350,  50, 760, 180, 620, 260, 560,  90, 700, 430, 130, 500, 370 };
static const int bubY[BUBBLE_COUNT] = { 80, 120, 500, 460, 300, 200, 520, 400, 100, 320, 260, 540, 560,  60, 160, 380, 470, 230,  40, 500, 150, 420, 340,  90 };
static const int bubR[BUBBLE_COUNT] = { 22, 18, 26, 20, 16, 24, 14, 28, 18, 22, 16, 20, 12, 15, 20, 17, 23, 13, 19, 16, 21, 14, 18, 25 };

static void DrawBackground() {
    DrawRectangleGradientV(0, 0, 800, 600, COL_BG_TOP, COL_BG_BOTTOM);
    for (int i = 0; i < BUBBLE_COUNT; ++i) {
        DrawCircle(bubX[i], bubY[i], (float)bubR[i], (Color){ 255, 255, 255, 40 });
        DrawCircle(bubX[i] - 4, bubY[i] - 4, (float)(bubR[i] / 3), (Color){ 255, 255, 255, 90 });
    }
}

static void DrawPanel(int x, int y, int w, int h) {
    Rectangle r = { (float)x, (float)y, (float)w, (float)h };
    DrawRectangleRounded(r, 0.15f, 8, COL_PANEL);
    DrawRectangleRoundedLinesEx(r, 0.15f, 8, 2, COL_BORDER);
}

static void DrawGlossyButton(int x, int y, int w, int h, const char* label, bool hover) {
    Rectangle r = { (float)x, (float)y, (float)w, (float)h };
    Color base = hover ? COL_BTN_HOVER : COL_BTN;
    DrawRectangleRounded(r, 0.4f, 8, base);
    // brilho superior (efeito vidro)
    Rectangle shine = { (float)x + 4, (float)y + 3, (float)w - 8, (float)(h / 2 - 4) };
    DrawRectangleRounded(shine, 0.4f, 8, COL_BTN_SHINE);
    DrawRectangleRoundedLinesEx(r, 0.4f, 8, 2, (Color){ 40, 120, 170, 255 });
    DrawText(label, x + 12, y + h / 2 - 10, 20, WHITE);
}

static bool Button(int x, int y, int w, int h, const char* label) {
    Rectangle r = { (float)x, (float)y, (float)w, (float)h };
    bool hover = CheckCollisionPointRec(GetMousePosition(), r);
    DrawGlossyButton(x, y, w, h, label, hover);
    return hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

// ---------- helpers de texto ----------
static void AppendChar(char* buf, int& len, int maxLen) {
    int key = GetCharPressed();
    while (key > 0) {
        if (key >= 32 && key <= 126 && len < maxLen - 1) {
            buf[len++] = (char)key;
            buf[len] = '\0';
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE) && len > 0) {
        buf[--len] = '\0';
    }
}

static void DrawTextBox(int x, int y, int w, int h, const char* buf) {
    DrawRectangle(x, y, w, h, (Color){ 255, 255, 255, 230 });
    DrawRectangleLines(x, y, w, h, COL_BORDER);
    DrawText(buf, x + 6, y + 6, 20, COL_TEXT);
}

static void DrawWrapped(const std::string& text, int x, int& y, int fontSize, int maxWidth, Color color) {
    std::istringstream iss(text);
    std::string word, line;
    while (iss >> word) {
        std::string test = line.empty() ? word : line + " " + word;
        if (MeasureText(test.c_str(), fontSize) > maxWidth && !line.empty()) {
            DrawText(line.c_str(), x, y, fontSize, color);
            y += fontSize + 3;
            line = word;
        } else {
            line = test;
        }
    }
    if (!line.empty()) {
        DrawText(line.c_str(), x, y, fontSize, color);
        y += fontSize + 3;
    }
}

static const char* nomeTema(int t) {
    if (t == 1) return "amor";
    if (t == 2) return "carreira";
    return "familia";
}

// ---------- telas ----------
static void TelaMenu() {
    DrawText("Leitor de Tarot", 30, 25, 36, COL_TITLE);
    DrawText("Escolha uma opcao", 30, 65, 18, COL_TEXT);
    DrawPanel(10, 100, 340, 260);
    if (Button(30, 120, 300, 42, "1. Fazer leitura")) { current = SCR_TEMA; statusMsg.clear(); }
    if (Button(30, 172, 300, 42, "2. Ver historico")) { current = SCR_HISTORICO; }
    if (Button(30, 224, 300, 42, "3. Buscar carta")) { current = SCR_BUSCAR; buscaBuf[0]='\0'; buscaLen=0; statusMsg.clear(); }
    if (Button(30, 276, 300, 42, "4. Listar baralho")) { current = SCR_LISTAR; }
    if (Button(30, 338, 300, 42, "0. Sair")) { fechar = true; }
}

static void TelaTema() {
    DrawText("Escolha o tema", 30, 25, 30, COL_TITLE);
    DrawPanel(10, 70, 260, 200);
    if (Button(30, 90, 220, 42, "1. Amor")) { temaEscolhido = 1; perguntaBuf[0]='\0'; perguntaLen=0; current = SCR_PERGUNTA; statusMsg.clear(); }
    if (Button(30, 142, 220, 42, "2. Carreira")) { temaEscolhido = 2; perguntaBuf[0]='\0'; perguntaLen=0; current = SCR_PERGUNTA; statusMsg.clear(); }
    if (Button(30, 194, 220, 42, "3. Familia")) { temaEscolhido = 3; perguntaBuf[0]='\0'; perguntaLen=0; current = SCR_PERGUNTA; statusMsg.clear(); }
    if (Button(30, 255, 220, 42, "Voltar")) { current = SCR_MENU; }
}

static void TelaPergunta() {
    char buf[64];
    std::snprintf(buf, sizeof(buf), "Tema: %s", nomeTema(temaEscolhido));
    DrawText(buf, 30, 25, 26, COL_TITLE);
    DrawText("Digite a pergunta:", 30, 65, 20, COL_TEXT);
    DrawTextBox(30, 95, 740, 32, perguntaBuf);
    AppendChar(perguntaBuf, perguntaLen, 256);

    if (Button(30, 145, 140, 42, "Confirmar")) {
        if (perguntaBuf[0] == '\0') {
            statusMsg = "Pergunta vazia. Tente novamente.";
        } else if (!tarot.criarLeitura(temaEscolhido, perguntaBuf)) {
            statusMsg = "Tema invalido.";
        } else {
            perguntaBuf[0] = '\0'; perguntaLen = 0;
            current = SCR_RESULTADO;
            statusMsg.clear();
        }
    }
    if (Button(190, 145, 120, 42, "Voltar")) { current = SCR_TEMA; statusMsg.clear(); }
    if (!statusMsg.empty()) DrawText(statusMsg.c_str(), 30, 210, 20, RED);
}

static void TelaResultado() {
    if (tarot.historicoVazio()) { current = SCR_MENU; return; }
    const LeituraTarot& ultima = tarot.getHistorico().back();
    char buf[128];
    std::snprintf(buf, sizeof(buf), "Leitura %d - %s", ultima.getNumero(), ultima.getTema().c_str());
    DrawText(buf, 30, 20, 26, COL_TITLE);
    std::snprintf(buf, sizeof(buf), "Pergunta: %s", ultima.getPergunta().c_str());
    DrawText(buf, 30, 52, 18, COL_TEXT);

    const std::vector<Carta>& cs = ultima.getCartas();
    const char* pos[3] = { "Passado", "Presente", "Futuro" };
    int y = 80;
    DrawPanel(15, 72, 770, 470);
    for (int i = 0; i < 3; ++i) {
        char linha[128];
        std::snprintf(linha, sizeof(linha), "%s: %s", pos[i], cs[i].getNome().c_str());
        DrawText(linha, 30, y, 20, COL_ACCENT);
        y += 24;
        std::string sig = cs[i].significadoParaTema(ultima.getTema());
        DrawWrapped(sig, 50, y, 18, 720, COL_TEXT);
        y += 10;
    }

    if (Button(30, 555, 140, 40, "Voltar")) { current = SCR_MENU; }
}

static void TelaHistorico() {
    DrawText("Historico de leituras", 30, 20, 26, COL_TITLE);
    DrawPanel(15, 60, 770, 480);
    int y = 75;
    if (tarot.historicoVazio()) {
        DrawText("Nenhuma leitura feita ainda.", 30, y, 20, COL_TEXT);
    } else {
        for (std::list<LeituraTarot>::const_iterator it = tarot.getHistorico().begin();
             it != tarot.getHistorico().end(); ++it) {
            char buf[256];
            std::snprintf(buf, sizeof(buf), "[Leitura %d] %s - \"%s\"", it->getNumero(), it->getTema().c_str(), it->getPergunta().c_str());
            DrawText(buf, 30, y, 18, COL_TEXT);
            y += 22;
            const std::vector<Carta>& cs = it->getCartas();
            std::snprintf(buf, sizeof(buf), "  Passado: %s | Presente: %s | Futuro: %s",
                          cs[0].getNome().c_str(), cs[1].getNome().c_str(), cs[2].getNome().c_str());
            DrawText(buf, 30, y, 16, (Color){ 80, 110, 140, 255 });
            y += 26;
            if (y > 520) break;
        }
    }
    if (Button(30, 555, 120, 40, "Voltar")) { current = SCR_MENU; }
}

static void TelaBuscar() {
    DrawText("Buscar carta pelo nome", 30, 20, 26, COL_TITLE);
    DrawTextBox(30, 65, 420, 32, buscaBuf);
    AppendChar(buscaBuf, buscaLen, 256);
    if (Button(30, 115, 120, 40, "Buscar")) {
        cartaBuscada = tarot.buscarCarta(buscaBuf);
        if (cartaBuscada == nullptr) {
            statusMsg = "Carta nao encontrada.";
        } else {
            statusMsg.clear();
            current = SCR_BUSCAR_RES;
        }
    }
    if (Button(170, 115, 120, 40, "Voltar")) { current = SCR_MENU; statusMsg.clear(); }
    if (!statusMsg.empty()) DrawText(statusMsg.c_str(), 30, 175, 20, RED);
}

static void TelaBuscarRes() {
    if (cartaBuscada == nullptr) { current = SCR_BUSCAR; return; }
    DrawText(cartaBuscada->getNome().c_str(), 30, 20, 30, COL_TITLE);
    char buf[128];
    std::snprintf(buf, sizeof(buf), "Categoria: %s", cartaBuscada->getCategoria().c_str());
    DrawText(buf, 30, 58, 18, COL_TEXT);
    DrawPanel(15, 85, 770, 460);
    int y = 100;
    DrawText("Significado geral:", 30, y, 18, COL_ACCENT); y += 22;
    DrawWrapped(cartaBuscada->getSignificadoGeral(), 45, y, 18, 720, COL_TEXT); y += 8;
    const char* temas[3] = { "amor", "carreira", "familia" };
    const char* rotulos[3] = { "Amor", "Carreira", "Familia" };
    for (int i = 0; i < 3; ++i) {
        char r[64];
        std::snprintf(r, sizeof(r), "%s:", rotulos[i]);
        DrawText(r, 30, y, 18, COL_ACCENT); y += 22;
        DrawWrapped(cartaBuscada->significadoParaTema(temas[i]), 45, y, 18, 720, COL_TEXT); y += 8;
    }
    if (Button(30, 555, 120, 40, "Voltar")) { current = SCR_BUSCAR; }
}

static void TelaListar() {
    DrawText("Baralho (ordem numerica)", 30, 20, 26, COL_TITLE);
    DrawPanel(15, 55, 770, 500);
    std::vector<Carta> ordenadas = tarot.baralhoOrdenado();
    int y = 70;
    int col = 0;
    for (std::size_t i = 0; i < ordenadas.size(); ++i) {
        char buf[64];
        std::snprintf(buf, sizeof(buf), "%2d. %s", ordenadas[i].getNumero() + 1, ordenadas[i].getNome().c_str());
        int x = (col == 0) ? 30 : 410;
        DrawText(buf, x, y, 18, COL_TEXT);
        if (col == 1) { y += 22; col = 0; } else { col = 1; }
    }
    if (Button(30, 560, 120, 40, "Voltar")) { current = SCR_MENU; }
}

int main() {
    std::srand(static_cast<unsigned int>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    InitWindow(800, 600, "Tarot - interface grafica");
    SetTargetFPS(60);

    while (!WindowShouldClose() && !fechar) {
        BeginDrawing();
        DrawBackground();

        switch (current) {
            case SCR_MENU: TelaMenu(); break;
            case SCR_TEMA: TelaTema(); break;
            case SCR_PERGUNTA: TelaPergunta(); break;
            case SCR_RESULTADO: TelaResultado(); break;
            case SCR_HISTORICO: TelaHistorico(); break;
            case SCR_BUSCAR: TelaBuscar(); break;
            case SCR_BUSCAR_RES: TelaBuscarRes(); break;
            case SCR_LISTAR: TelaListar(); break;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
