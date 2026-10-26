# Plano de implementação

## Classes e arquivos

| Classe | Arquivos | O que guarda | Métodos principais |
| --- | --- | --- | --- |
| Carta | `include/Carta.hpp`, `src/Carta.cpp` | nome, categoria, significado geral, `map<string,string>` significados por tema | getters, `significadoParaTema`, `operator<` (por nome), `operator==` (por nome) |
| Baralho | `include/Baralho.hpp`, `src/Baralho.cpp` | `vector<Carta>` com as 22 cartas; `set<string>` das cartas já tiradas | construtor carrega as 22, `sortear3()`, `getCartas()` |
| LeituraTarot | `include/LeituraTarot.hpp`, `src/LeituraTarot.cpp` | número, tema, pergunta, `vector<Carta>` (3) | getters |
| Tarot | `include/Tarot.hpp`, `src/Tarot.cpp` | `Baralho` + `list<LeituraTarot>` histórico + contador | `criarLeitura`, `listarHistorico`, `buscarCarta`, `baralhoOrdenado` |
| Interface | `src/main.cpp` | menu (lê e mostra) | sem regra de negócio |

## Onde uso a STL e por quê

- **map<string,string>** em `Carta`: liga tema → significado. É o que faz a mesma carta significar coisas diferentes em amor/carreira/família. Um `vector` não serviria porque quero buscar pelo tema pelo nome, não por posição.
- **set<string>** em `Baralho`: guarda os nomes já tirados para garantir 3 cartas diferentes sem repetição. `set` cuida disso sozinho.
- **list<LeituraTarot>** em `Tarot`: histórico em que só adiciono no fim e percorro para listar, não preciso acessar por índice.
- **vector<Carta>** em `Baralho`: sequência fixa que percorro e ordeno.
- **sort + operator<**: `baralhoOrdenado()` ordena as cartas por nome.
- **find + operator==**: `buscarCarta()` localiza uma carta pelo nome.

## Etapas (uma por vez, cada uma compila e testa)

1. **Carta + Baralho**: as 22 cartas carregadas; interface mínima lista o baralho em ordem alfabética (`sort` + `operator<`).
2. **Sorteio**: `Baralho::sortear3()` sem repetir (`set`); interface mostra 3 cartas sorteadas.
3. **LeituraTarot + Tarot**: tema, pergunta, número e histórico; menu com "1. Fazer leitura" e "2. Ver histórico".
4. **Busca e ordenação**: `buscarCarta` (`find` + `operator==`); menu com "3. Buscar carta" e "4. Listar baralho".
5. **Erros e testes**: tema inválido, pergunta vazia, entrada não numérica, histórico vazio, carta não encontrada; criar `exemplos/` e escrever o comando de compilação no `README.md`.
