# Descrição do sistema

O sistema é um "leitor" de tarot. Você pode escolher 3 temas: amor, carreira e família. Cada leitura
faz uma tiragem de 3 cartas (passado, presente e futuro) e cada carta tem um significado próprio
para cada tema. 

## Nome e ideia

É um leitor de tarot e vai ler a sua sorte em um determinado campo da sua vida, no passado, presente e futuro. Escolhi esse tema por diversão e não acho que ele vá servir de fato para alguém, pois ninguém vai fazer tiragem com uma máquina. Mas eu achei legal!

## O que o sistema guarda

Carta: nome, categoria, significado geral e um significado por tema. 
Baralho: as 22 cartas dos arcanos maiores. 
LeituraTarot: o número da leitura, o tema, a pergunta e as três cartas (passado/presente/futuro).
Tarot: o baralho e a lista (histórico) das leituras da sessão.

## O que dá para fazer

1. Fazer uma leitura

Pede: o tema (1-amor, 2-carreira, 3-família) e, depois, a pergunta.
Mostra: as três cartas sorteadas, uma por posição, cada uma com o significado daquele tema. Ex.:
Passado: O Enamorado — em amor, indica uma escolha afetiva...
Presente: A Torre — ...
Futuro: O Sol — ...
Guarda a leitura no histórico.

2. Ver o histórico de leituras

Mostra cada leitura da sessão, na ordem em que foi feita, numerada (Leitura 1, 2, 3...), com tema, pergunta e as três cartas.

3. Buscar uma carta pelo nome

Pede: o nome (ex.: "O Sol").
Mostra: o significado geral e os significados por tema. Usa find + operator==.

4. Listar o baralho em ordem numérica

Mostra: as 22 cartas em ordem de numero do arcano. Usa sort + operator<.

0. Sair



## Regras

1. O baralho tem sempre as 22 cartas dos arcanos maiores, definidas no código; o usuário não cadastra cartas.
2. Toda leitura começa pela escolha do tema (1-amor, 2-carreira, 3-família); a pergunta só é lida depois do tema.
3. Cada leitura sorteia 3 cartas diferentes, uma para cada posição, nesta ordem: 1ª = passado, 2ª = presente, 3ª = futuro.
4. Uma carta pode sair em leituras diferentes; o que não pode é repetir na mesma leitura.
5. O histórico guarda todas as leituras da sessão e some ao fechar o programa (ainda não há arquivos) .
6. A busca por carta exige o nome exatamente como está no baralho (ex.: "O Sol").

## Quando algo dá errado

1. Tema inválido (número fora de 1–3, ou texto): avisa e volta ao menu sem criar a leitura.
2. Pergunta vazia: não aceita; pede a pergunta de novo.
3. Carta não encontrada na busca: mostra "Carta não encontrada." e volta ao menu.
4. Histórico vazio (opção 2): mostra "Nenhuma leitura feita ainda.".
5. Entrada inválida no menu (texto onde se espera número): avisa "Opção inválida." e volta ao menu, sem travar.

## Classes que eu imagino

1. Carta: guarda nome, categoria, significado geral e os significados por tema de uma carta.
2. Baralho: mantém as 22 cartas e sorteia 3 cartas diferentes para uma leitura.
3. LeituraTarot: guarda o número da leitura, o tema, a pergunta e as três cartas sorteadas.
4. Tarot: reúne o baralho e o histórico; cria leituras e responde às consultas da interface.
5. Interface (arquivos separados): lê as opções do menu e mostra os resultados

## Exemplo de uso

Tarot - leitura de tarot
1. Fazer leitura
2. Ver historico
3. Buscar carta
4. Listar baralho
0. Sair

Opcao: 1

Tema (1-amor 2-carreira 3-familia): 1
Pergunta: devo continuar esse relacionamento?

Passado: O Enamorado - uma escolha afetiva...
Presente: A Torre - ...
Futuro: O Sol - ...

...
Opcao: 2

Historico:
[Leitura 2] Amor - "devo continuar esse relacionamento?"
  Passado: O Enamorado | Presente: A Torre | Futuro: O Sol

...
Opcao: 0
Ate logo!
