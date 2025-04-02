Trabalho Prático 3 - Estruturas de Dados
Descrição do Problema

Na cidade de Nlogônia, as crianças têm o hábito de aplicar transformações lineares a pontos desenhados em uma folha de papel como parte de seus hobbies matemáticos. As transformações são aplicadas em diferentes instantes de tempo, e cada instante está associado a uma transformação linear. O objetivo é determinar a posição em que um ponto morre, dado o tempo e a posição de seu nascimento, o tempo de morte e as transformações aplicadas. As transformações podem ser alteradas ao longo da brincadeira, mas apenas uma de cada vez.
Formalizando o Problema

O problema é formalizado por meio de matrizes 2x2, representando as transformações lineares associadas a cada instante de tempo. As operações possíveis são atualização, onde uma matriz pode ser substituída, e consulta, onde é necessário determinar as coordenadas finais de um ponto.
Abordagem Ineficiente

Uma solução ingênua seria armazenar cada transformação em um array indexado pelos instantes de tempo. No entanto, isso seria ineficiente para o grande número de operações que as crianças realizam.
Árvore de Segmentação

A solução proposta é utilizar uma árvore de segmentação (segtree), que pré-computa a solução para alguns subarranjos, permitindo operações de consulta e atualização eficientes.
Implementação

O código deve ser implementado em C ou C++ seguindo a estrutura de pastas especificada. A compilação é feita por meio do Makefile, gerando o executável tp3.out na pasta bin.
Entrada e Saída

As instâncias são lidas pela entrada padrão, com operações de atualização e consulta. A saída esperada inclui as coordenadas finais dos pontos.
Documentação

A documentação deve seguir um modelo específico, incluindo capa, introdução, método, análise de complexidade, estratégias de robustez, análise experimental, conclusões e bibliografia.