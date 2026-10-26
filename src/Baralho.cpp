#include "Baralho.hpp"

#include <cstdlib>
#include <set>

Baralho::Baralho() {
    adicionarCarta("O Louco", "Arcano Maior",
        "Novos começos, impulso e aventura; o ponto de partida de toda jornada.",
        "Um novo romance cheio de espontaneidade pode surgir, talvez de forma inesperada. Nao tenha medo de se arriscar, pois a inocencia e a coragem atraem encontros leves e verdadeiros. Evite, porem, decisoes impulsivas que ignorem seus sentimentos reais.",
        "Uma oportunidade inesperada pode aparecer e pedir que voce saia da zona de conforto. Aceite o desafio mesmo sem garantias, confiando em sua capacidade de improvisar. O risco calculado tende a abrir portas que a cautela fecharia.",
        "A dinamica familiar pode mudar de forma repentina, talvez com a chegada de alguem novo ou uma mudanca de rotina. Abrace o inesperado em vez de resistir, pois isso renova os lacos. Momentos de leveza e diversao fortalecem a uniao.");
    adicionarCarta("O Mago", "Arcano Maior",
        "Habilidade, vontade e manifestacao; voce tem os recursos para agir.",
        "Voce tem o poder de atrair o parceiro ideal, desde que aja com confianca e clareza sobre o que deseja. Suas palavras e gestos tem peso agora; use-os para construir, nao para impressionar. A comunicacao aberta transforma atracao em vinculo.",
        "Seus talentos estao em alta e e hora de iniciar um projeto que vinha adiando. Concentre sua vontade em uma unica direcao e manifeste resultados concretos. Evite dispersar energia em muitas frentes ao mesmo tempo.",
        "Sua lideranca e iniciativa fortalecem os lacos familiares. Tome a frente em decisoes importantes e mostre com acoes, nao so com palavras, que esta presente. A familia se organiza melhor quando alguem assume o comando com respeito.");
    adicionarCarta("A Sacerdotisa", "Arcano Maior",
        "Intuicao, misterio e conhecimento interior; o que esta oculto vem a tona.",
        "Confie na sua intuicao sobre a pessoa, pois ela percebe o que as palavras escondem. Segredos podem surgir e pedir maturidade para serem lidados. Escute mais do que fala antes de tomar uma decisao afetiva.",
        "Ouca sua voz interior antes de decidir, pois o momento favorece estudo e reflexao. Evite agir por pressao externa e busque informacoes antes de se comprometer. O silencio pode ser mais produtivo do que a acao agora.",
        "Uma verdade nao dita afeta a familia; observe em silencio antes de confrontar. Sua sensibilidade percebe tensões que outros ignoram. Use essa intuicao para mediar, nao para acusar.");
    adicionarCarta("A Imperatriz", "Arcano Maior",
        "Fertilidade, abundancia e cuidado; nutrir e ser nutrido.",
        "O relacionamento tende a ser fertil e afetuoso, com possibilidade de compromisso ou aprofundamento. Expresse carinho de forma concreta e deixe o parceiro se sentir acolhido. A generosidade afetiva colhe frutos duradouros.",
        "Criatividade e prosperidade marcam o trabalho, com bons frutos vindo de projetos bem cuidados. Invista em ideias que envolvam beleza, arte ou atendimento ao publico. O cuidado com os detalhes diferencia seu resultado.",
        "Harmonia e crescimento familiar estao em destaque, com foco em cuidar dos seus. Momentos de convivio e celebracao fortalecem os lacos. Evite negligenciar a propria necessidade de descanso enquanto cuida dos outros.");
    adicionarCarta("O Imperador", "Arcano Maior",
        "Autoridade, estrutura e controle; liderar com responsabilidade.",
        "A relacao tende a ser estavel e protetora, com alguem firme ao seu lado. Estabeleca limites claros e construa confianca por meio da constancia. Evite o excesso de controle, que pode sufocar o parceiro.",
        "Promocao ou lideranca podem surgir, pedindo que organize seus projetos com rigor. Assuma o comando de forma justa e delegue com clareza. A estrutura que voce cria hoje sustenta o sucesso de amanha.",
        "Uma figura de autoridade fortalece o lar; estabeleca regras claras e justas. A familia se sente segura quando sabe o que esperar. Liderar aqui significa proteger, nao dominar.");
    adicionarCarta("O Hierofante", "Arcano Maior",
        "Tradicao, ensino e valores; o que e passado de geracao em geracao.",
        "O momento favorece compromisso formal, casamento ou alinhamento de valores com o parceiro. Converse sobre expectativas e projetos de longo prazo. A uniao se fortalece quando ambos compartilham os mesmos principios.",
        "O aprendizado com mentores e a adesao as regras do ambiente trazem seguranca. Busque orientacao de quem tem mais experiencia antes de inovar. A tradicao, bem usada, acelera seu crescimento.",
        "Tradicoes e valores familiares estao em destaque, talvez com rituais, festas ou costumes. Transmita aos mais jovens o que considera essencial. Respeitar a historia da familia fortalece a identidade de todos.");
    adicionarCarta("Os Enamorados", "Arcano Maior",
        "Escolha, uniao e afeto; o coracao diante de uma decisao.",
        "Uma decisao importante no campo afetivo se apresenta, podendo levar a uniao de coracoes. Escolha com o coracao e com a razao, pois o compromisso exigira verdade. O dialogo sincero evita arrependimentos.",
        "Voce pode ter de escolher entre duas oportunidades; siga o que ama de verdade. A decisao deve refletir seus valores, nao apenas o ganho imediato. O caminho escolhido com paixao tende a prosperar.",
        "Uma reconciliacao ou uma escolha que afeta a familia pode surgir. Envolva os afetados na decisao para evitar ressentimentos. O amor, quando compartilhado, transforma conflitos em uniao.");
    adicionarCarta("O Carro", "Arcano Maior",
        "Vitoria, determinacao e avanco; mover-se com foco.",
        "Avance no relacionamento com determinacao, superando insegurancas e medos. A iniciativa de um dos dois pode destravar a relacao. Mantenha o controle emocional para nao atropelar o parceiro.",
        "Sucesso e conquista estao ao alcance, desde que supere obstaculos com foco. Defina um objetivo claro e nao se distraia com desvios. A disciplina transforma ambição em resultado.",
        "Movimento e progresso marcam o lar, talvez com mudanca de casa ou viagem em familia. Organize a logistica com antecedencia para evitar estresse. A uniao da familia no deslocamento fortalece os lacos.");
    adicionarCarta("A Forca", "Arcano Maior",
        "Coragem, paciencia e dominio; forca interior, nao bruta.",
        "Paciencia e compreensao fortalecem o vinculo, especialmente em momentos de tensao. Domine seus impulsos e responda com calma em vez de reagir. A ternura costuma vencer onde a forca falha.",
        "Supere desafios com calma e perseveranca, sem ceder a pressao. A constancia vence a resistencia do ambiente. Evite confrontos diretos e prefira a influencia suave.",
        "Serenidade para lidar com conflitos familiares e ser o porto seguro dos seus. Sua paciencia inspira os demais a baixar a guarda. Lidere pelo exemplo, nao pela imposicao.");
    adicionarCarta("O Eremita", "Arcano Maior",
        "Introspeccao, busca e solidao; a luz que se carrega sozinho.",
        "Momento de refletir sobre o que voce realmente quer, sem se precipitar em compromissos. A solidao pode ser fertil e ajudar a clarear seus desejos. Nao force uma relacao que ainda nao esta madura.",
        "Periodo de estudo e especializacao, afastando-se do ruido para aprofundar conhecimento. Invista em formacao e pesquisa antes de agir. A retirada temporaria do cenario acelera o crescimento.",
        "Necessidade de espaco e reflexao sobre seus vinculos familiares. Explique aos seus que o afastamento nao e abandono, mas busca de clareza. A familia compreende melhor quando ha comunicacao.");
    adicionarCarta("A Roda da Fortuna", "Arcano Maior",
        "Mudanca, ciclo e destino; o que sobe pode descer e vice-versa.",
        "Uma reviravolta afetiva pode ocorrer: o que estava parado se move. Aproveite a onda favoravel sem se agarrar ao passado. Flexibilidade emocional evita sofrimento diante do inesperado.",
        "Mudanca de fase no trabalho; aproveite a onda e adapte-se rapidamente. Novas oportunidades surgem de onde menos se espera. Mantenha-se aberto a caminhos alternativos.",
        "Mudancas na familia, talvez mudanca de cidade ou nova rotina, pedem adaptacao. Aceite os ciclos sem resistencia e apoie os seus na transicao. A uniao facilita qualquer mudanca.");
    adicionarCarta("A Justica", "Arcano Maior",
        "Equilibrio, verdade e causa e efeito; colher o que se plantou.",
        "Clareza e honestidade sao essenciais no relacionamento agora. Resolva pendencias com transparencia e evite jogos de poder. A justica afetiva pede que ambos assumam sua parte.",
        "Decisoes justas e contratos favoraveis estao em jogo; avalie com imparcialidade. Documente acordos e evite atalhos. A etica profissional traz resultados duradouros.",
        "Resolucao justa de conflitos familiares, talvez com mediacao ou dialogo franco. Evite tomar partido e busque o equilibrio entre os envolvidos. A verdade, dita com respeito, cura.");
    adicionarCarta("O Enforcado", "Arcano Maior",
        "Sacrificio, pausa e nova perspectiva; ver de cabeca para baixo.",
        "Suspensao no relacionamento: veja a situacao de outro angulo antes de agir. A pausa pode ser fertil e evitar decisoes precipitadas. Aceitar a espera e, por si so, um ato de amor.",
        "Pausa estrategica no trabalho; nao force resultados agora. Use o tempo para reavaliar metas e metodos. A aparente inacao pode ser preparacao para um salto.",
        "Solte o controle e aceite a situacao familiar como ela e. A resistencia prolonga o sofrimento; a aceitacao abre caminho. Peça ajuda se precisar, sem vergonha.");
    adicionarCarta("A Morte", "Arcano Maior",
        "Transformacao, fim e renascimento; o que morre da lugar ao novo.",
        "Fim de um ciclo afetivo para renascer outro, talvez mais autentico. Nao tema o encerramento; ele prepara o terreno para o que vem. O luto bem vivido liberta.",
        "Encerramento de fase profissional, com nova etapa se abrindo. Deixe ir o que nao funciona mais e abrace o recomeço. A transformacao profissional costuma ser libertadora.",
        "Transformacao na familia, talvez com perda ou mudanca profunda. Acolha o luto e apoie os seus no processo. O que se encerra abre espaço para novos vinculos.");
    adicionarCarta("A Temperanca", "Arcano Maior",
        "Equilibrio, moderacao e harmonia; misturar sem perder a essencia.",
        "O relacionamento tende a ser equilibrado e sereno, com dialogo maduro. Evite extremos e busque o meio-termo nas diferencas. A paciencia e a moderacao sustentam o amor.",
        "Concilie tarefas e mantenha o ritmo, sem sobrecarregar nem subutilizar. A gestao do tempo e da energia e a chave. Pequenos ajustes diarios evitam grandes crises.",
        "Paz e harmonia no lar, com moderacao nas palavras e nas reacoes. Evite discussões acaloradas e busque o consenso. A casa se torna refugio quando ha equilibrio.");
    adicionarCarta("O Diabo", "Arcano Maior",
        "Tentacao, apego e materialismo; o que nos prende.",
        "A relacao pode ser intensa, mas talvez toxica; cuidado com ciume e possessividade. Examine seus apegos e o que voce esta disposto a perder. A liberdade emocional e o primeiro passo para a saude.",
        "Ambicao excessiva pode cegar; nao se prenda a vicios ou atalhos. Questione se o ganho material compensa o desgaste. A independencia financeira nao deve custar sua integridade.",
        "Lacos que prendem, como dependencia emocional ou financeira, podem sufocar. Liberte-se de padroes repetitivos e estabeleca limites saudaveis. A familia cresce quando cada um tem sua autonomia.");
    adicionarCarta("A Torre", "Arcano Maior",
        "Ruptura, revelacao e mudanca brusca; o que desmorona.",
        "Uma revelacao pode abalar o relacionamento, mas a reconstrucao e possivel. Aceite a verdade mesmo quando doer e use-a para reconstruir sobre bases solidas. O que cai nao era sustentavel.",
        "Mudanca repentina no trabalho; adapte-se sem resistir ao inevitavel. O choque inicial da lugar a novas estruturas mais sadias. Mantenha a calma e reorganize-se.",
        "Uma noticia pode alterar a dinamica familiar; seja resiliente e apoie os seus. A comunicacao clara evita que o susto vire crise. Juntos, a familia supera o abalo.");
    adicionarCarta("A Estrela", "Arcano Maior",
        "Esperanca, inspiracao e serenidade; a luz que guia.",
        "Renovacao da fe no amor e cura afetiva apos um periodo dificil. Abra-se para novas possibilidades sem medo de se decepcionar. A esperanca, quando genuina, atrai o que se deseja.",
        "Inspiracao e novas ideias surgem; siga sua vocacao com confianca. Compartilhe sua visao e inspire a equipe. O momento favorece projetos criativos e altruistas.",
        "Esperanca e cura nas relacoes familiares, com reconciliacoes possiveis. Ofereca apoio e receba com gratidao. A serenidade de um membro contagia todos os outros.");
    adicionarCarta("A Lua", "Arcano Maior",
        "Ilusao, medo e inconsciente; o que se esconde na noite.",
        "Confusao afetiva pode surgir; nao tire conclusoes precipitadas. As aparências enganam e os medos projetam sombras. Espere a neblina dissipar antes de decidir.",
        "Incertezas no trabalho pedem cautela; confie na intuicao, mas verifique os fatos. Evite decisoes irreversiveis em meio a duvidas. A clareza vem com o tempo.",
        "Mal-entendidos familiares podem ocorrer; esclareca com calma e paciencia. Nao assuma intencoes sem perguntar. A escuta ativa dissipa ilusoes.");
    adicionarCarta("O Sol", "Arcano Maior",
        "Alegria, sucesso e vitalidade; a luz que revela tudo.",
        "Felicidade e clareza no relacionamento, com comunicacao aberta e calorosa. Momento propicio para celebrar a uniao e fortalecer o vinculo. A transparencia elimina duvidas e insegurancas.",
        "Sucesso e reconhecimento estao ao alcance; momento de brilhar e mostrar resultados. Aproveite a visibilidade para consolidar sua posicao. A confianca em si atrai oportunidades.",
        "Alegria e uniao familiar, com celebracoes e momentos de lazer juntos. Aproveite para fortalecer os lacos em clima leve. A felicidade compartilhada multiplica-se.");
    adicionarCarta("O Julgamento", "Arcano Maior",
        "Renascimento, chamado e avaliacao; o momento de prestar contas.",
        "Reconciliacao ou chamado para recomecar uma relacao que parecia encerrada. Perdoe e peca perdao, liberando o passado. O renascimento afetivo exige coragem e humildade.",
        "Avaliacao de desempenho e nova oportunidade profissional podem surgir. Analise seus resultados com honestidade e ajuste o rumo. O chamado pode vir de onde menos se espera.",
        "Perdao e reconciliacao familiar, com cura de feridas antigas. Abra espaço para o dialogo e a verdade. A familia se renova quando solta o ressentimento.");
    adicionarCarta("O Mundo", "Arcano Maior",
        "Conclusao, realizacao e plenitude; o fim de um ciclo maior.",
        "Realizacao afetiva; o ciclo se completa com maturidade e plenitude. Celebre o que foi construido e prepare-se para um novo começo. A relacao atinge um nivel de harmonia duradoura.",
        "Sucesso e conclusao de projeto, com reconhecimento pelo trabalho bem feito. Finalize com excelencia e comemore a conquista. O encerramento abre espaço para novos desafios.",
        "Harmonia e realizacao familiar, com sensacao de completude e pertencimento. Aproveite para celebrar as conquistas coletivas. A familia, unida, sente-se inteira.");
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
    Carta c(cartas.size(), nome, categoria, significadoGeral);
    c.adicionarSignificado("amor", sigAmor);
    c.adicionarSignificado("carreira", sigCarreira);
    c.adicionarSignificado("familia", sigFamilia);
    cartas.push_back(c);
}
