#include "Baralho.hpp"

#include <cstdlib>
#include <set>

Baralho::Baralho() {
    adicionarCarta("O Louco", "Arcano Maior",
        "Novos começos, impulso e aventura.",
        "Um novo romance cheio de espontaneidade; nao tenha medo de se arriscar.",
        "Oportunidade inesperada; aceite o desafio mesmo sem garantias.",
        "Mudanca na dinamica familiar; abrace o inesperado.");
    adicionarCarta("O Mago", "Arcano Maior",
        "Habilidade, vontade e manifestacao.",
        "Voce tem o poder de atrair o parceiro ideal; aja com confianca.",
        "Seus talentos estao em alta; e hora de iniciar um projeto.",
        "Sua lideranca fortalece os lacos familiares.");
    adicionarCarta("A Sacerdotisa", "Arcano Maior",
        "Intuicao, misterio e conhecimento interior.",
        "Confie na sua intuicao sobre a pessoa; segredos podem surgir.",
        "Ouca sua voz interior antes de decidir; momento de estudar.",
        "Uma verdade nao dita afeta a familia; observe em silencio.");
    adicionarCarta("A Imperatriz", "Arcano Maior",
        "Fertilidade, abundancia e cuidado.",
        "Relacionamento fertil e afetuoso; possibilidade de compromisso.",
        "Criatividade e prosperidade; bons frutos no trabalho.",
        "Harmonia e crescimento familiar; cuide dos seus.");
    adicionarCarta("O Imperador", "Arcano Maior",
        "Autoridade, estrutura e controle.",
        "Relacao estavel e protetora; alguem firme ao seu lado.",
        "Promocao ou lideranca; organize seus projetos.",
        "Figura de autoridade fortalece o lar; estabeleca regras claras.");
    adicionarCarta("O Hierofante", "Arcano Maior",
        "Tradicao, ensino e valores.",
        "Compromisso formal ou casamento; valores compartilhados.",
        "Aprendizado com mentores; siga as regras do ambiente.",
        "Tradicoes e valores familiares em destaque.");
    adicionarCarta("Os Enamorados", "Arcano Maior",
        "Escolha, uniao e afeto.",
        "Decisao importante no campo afetivo; uniao de coracoes.",
        "Escolha entre duas oportunidades; siga o que ama.",
        "Reconciliacao ou escolha que afeta a familia.");
    adicionarCarta("O Carro", "Arcano Maior",
        "Vitoria, determinacao e avanco.",
        "Avance no relacionamento com determinacao.",
        "Sucesso e conquista; supere obstaculos com foco.",
        "Movimento e progresso no lar; viagem em familia.");
    adicionarCarta("A Forca", "Arcano Maior",
        "Coragem, paciencia e dominio.",
        "Paciencia e compreensao fortalecem o vinculo.",
        "Supere desafios com calma e perseveranca.",
        "Serenidade para lidar com conflitos familiares.");
    adicionarCarta("O Eremita", "Arcano Maior",
        "Introspeccao, busca e solidao.",
        "Momento de refletir sobre o que quer; nao se precipite.",
        "Periodo de estudo e especializacao; afaste-se do ruido.",
        "Necessidade de espaco; reflita sobre seus vinculos.");
    adicionarCarta("A Roda da Fortuna", "Arcano Maior",
        "Mudanca, ciclo e destino.",
        "Reviravolta afetiva; o que era parado se move.",
        "Mudanca de fase no trabalho; aproveite a onda.",
        "Mudancas na familia; adapte-se aos ciclos.");
    adicionarCarta("A Justica", "Arcano Maior",
        "Equilibrio, verdade e causa e efeito.",
        "Clareza e honestidade no relacionamento.",
        "Decisoes justas; contratos e acordos favoraveis.",
        "Resolucao justa de conflitos familiares.");
    adicionarCarta("O Enforcado", "Arcano Maior",
        "Sacrificio, pausa e nova perspectiva.",
        "Suspensao; veja o relacionamento de outro angulo.",
        "Pausa estrategica; nao force resultados agora.",
        "Solte o controle e aceite a situacao familiar.");
    adicionarCarta("A Morte", "Arcano Maior",
        "Transformacao, fim e renascimento.",
        "Fim de um ciclo afetivo para renascer outro.",
        "Encerramento de fase profissional; nova etapa.",
        "Transformacao na familia; deixe o velho ir.");
    adicionarCarta("A Temperanca", "Arcano Maior",
        "Equilibrio, moderacao e harmonia.",
        "Relacionamento equilibrado e sereno.",
        "Concilie tarefas e mantenha o ritmo.",
        "Paz e harmonia no lar; moderacao nas palavras.");
    adicionarCarta("O Diabo", "Arcano Maior",
        "Tentacao, apego e materialismo.",
        "Relacao intensa mas talvez toxica; cuidado com ciume.",
        "Ambicao excessiva; nao se prenda a vicios.",
        "Lacos que prendem; liberte-se de padroes.");
    adicionarCarta("A Torre", "Arcano Maior",
        "Ruptura, revelacao e mudanca brusca.",
        "Revelacao que abala o relacionamento; reconstrucao.",
        "Mudanca repentina no trabalho; adapte-se.",
        "Noticia que altera a familia; seja resiliente.");
    adicionarCarta("A Estrela", "Arcano Maior",
        "Esperanca, inspiracao e serenidade.",
        "Renovacao da fe no amor; cura afetiva.",
        "Inspiracao e novas ideias; siga sua vocacao.",
        "Esperanca e cura nas relacoes familiares.");
    adicionarCarta("A Lua", "Arcano Maior",
        "Ilusao, medo e inconsciente.",
        "Confusao afetiva; nao tire conclusoes precipitadas.",
        "Incertezas no trabalho; confie na intuicao.",
        "Mal-entendidos familiares; esclareca com calma.");
    adicionarCarta("O Sol", "Arcano Maior",
        "Alegria, sucesso e vitalidade.",
        "Felicidade e clareza no relacionamento.",
        "Sucesso e reconhecimento; momento de brilhar.",
        "Alegria e uniao familiar; celebre juntos.");
    adicionarCarta("O Julgamento", "Arcano Maior",
        "Renascimento, chamado e avaliacao.",
        "Reconciliacao ou chamado para recomecar.",
        "Avaliacao de desempenho; nova oportunidade.",
        "Perdao e reconciliacao familiar.");
    adicionarCarta("O Mundo", "Arcano Maior",
        "Conclusao, realizacao e plenitude.",
        "Realizacao afetiva; ciclo se completa.",
        "Sucesso e conclusao de projeto; reconhecimento.",
        "Harmonia e realizacao familiar.");
}

std::vector<Carta> Baralho::sortear3() {
    std::set<std::string> usados;
    std::vector<Carta> resultado;

    while (resultado.size() < 3) {
        int i = std::rand() % cartas.size();
        const std::string& nome = cartas[i].getNome();
        if (usados.find(nome) == usados.end()) {
            usados.insert(nome);
            resultado.push_back(cartas[i]);
        }
    }

    return resultado;
}

const std::vector<Carta>& Baralho::getCartas() const {
    return cartas;
}

std::size_t Baralho::tamanho() const {
    return cartas.size();
}

void Baralho::adicionarCarta(const std::string& nome, const std::string& categoria,
                             const std::string& significadoGeral,
                             const std::string& sigAmor, const std::string& sigCarreira,
                             const std::string& sigFamilia) {
    Carta c(nome, categoria, significadoGeral);
    c.adicionarSignificado("amor", sigAmor);
    c.adicionarSignificado("carreira", sigCarreira);
    c.adicionarSignificado("familia", sigFamilia);
    cartas.push_back(c);
}
