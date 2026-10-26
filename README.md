# Leitor de Tarot

Atividade da Unidade 2 de Linguagem de Programação I. Leia `ENUNCIADO.md`
antes de começar.

Esse é um Leitor de Tarot. A descrição completa está em
`DESCRICAO.md`.

## Arquivos

```text
.
├── AGENTS.md       regras que a IA lê antes de cada pedido
├── DESCRICAO.md    a descrição do sistema, escrita por você
├── ENUNCIADO.md    a atividade
├── PLANO.md        o plano feito com a IA (criado na etapa 3)
├── README.md       este arquivo
├── exemplos/       arquivos de entrada para testar
├── include/        um .hpp por classe
└── src/            um .cpp por classe, mais a interface
```

## Compilar e executar

```bash
g++ -std=c++11 -Wall -Wextra src/*.cpp -Iinclude -o sistema
./sistema
```

Se o comando mudar, atualize esta seção. Na correção eu vou usar o que
estiver escrito aqui.

## Onde uso a STL

Escreva esta seção sem IA. Para cada container ou algoritmo da STL que o
sistema usa: em que classe ele está, o que guarda, e por que você escolheu
ele e não outro.

| Onde | O quê | Por quê |
| --- | --- | --- |
| Carta | map<string,string> (significadosPorTema) | liga tema → significado, busca pelo nome do tema, não por posição |
| Baralho | set<string> (cartas já tiradas) | garante 3 cartas diferentes sem repetição, insert ignora duplicata |
| Tarot | list<LeituraTarot> (histórico) | só adiciono no fim e percorro para listar, não preciso de índice |
| Baralho | vector<Carta> (as 22 cartas) | sequência fixa que percorro e ordeno |
| Tarot::baralhoOrdenado() | sort + operator< da Carta | ordena as cartas por nome |
| Tarot::buscarCarta() | find + operator== da Carta | localiza uma carta pelo nome |

## Como usei a IA

Escreva com as suas palavras:

- Modelo usado: Big Pickle (OpenCode Zen), gratuito.
- Um pedido que deu certo, e por que você acha que deu certo: pedir uma etapa do plano por vez, com "antes de editar, diga quais arquivos vai criar" assim o código veio pequeno e compilável.
- Um pedido que deu errado, o que veio errado e como você mudou o pedido: como eu fiz passo a passo e especifiquei os contâiners permitidos, e pela natureza simples do projeto, nao tive problemas.
- Uma coisa que a IA sugeriu e você recusou, e por quê: A IA queria guardar data e hora pra organizar a ordem das perguntas, totalmente desnecessário. Aí eu pedi pra fazer de outra forma e a sugestão foi atribuir a primeira leitura o número 1, a leitura 2 o número 2 e etc. Daí eu acatei.
