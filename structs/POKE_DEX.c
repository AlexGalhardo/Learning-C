/*
Questão 1 (6.0 Pontos) - Pokedex

Está acabando o semestre, e você não vê a hora de dar um fim aos estudos e voltar à sua jornada para se tornar um mestre Pokémon!

Mas antes, o professor Carvalho acaba de te passar uma missão para ajudá-lo!

Você deverá criar a estrutura de uma Pokedéx para ajudá-lo a estudar os Pokémon!
Cada Pokémon terá:
Nome (máximo de 50 caracteres)
Tipo primário(máximo de 20 caracteres)
Tipo secundário(máximo de 20 caracteres)
Uma lista de atributos (ou status)
Uma lista de 4 ataques possíveis

É claro que como um bom treinador você sabe que será mais fácil que os atributos e os ataques do Pokémon estejam em estruturas próprias, sendo que os atributos contém 6 inteiros:
HP
Ataque
Defesa
Ataque Especial
Defesa Especial
Velocidade

E cada ataque possui os seguintes atributos:
Nome (Máximo de 20 caracteres)
Poder base (inteiro)
Acurácia (float)
Classe (char: 'p' para físico, 's' para especial)

Você não sabe quantos Pokémon irá cadastrar, portanto, use alocação dinâmica! E lembre-se de adicioná-los em sequência!
Seu programa deverá, primeiramente, ler comandos (inteiro), até o comando 0 ser digitado.
Serão 4 possíveis comandos:

1 - Cadastrar um novo Pokémon (sem seus ataques):
Você deverá ler, na ordem:
Nome do Pokémon
Tipo primário
Tipo secundário
HP
Ataque
Defesa
Ataque especial
Defesa especial
Velocidade

2 - Adicionar 1 ataque à lista de 1 Pokémon específico. Você deverá ler:
Índice do Pokémon no vetor
Índice do ataque no vetor de ataques do Pokémon (de 0 a 3)
Nome do ataque
Poder base do ataque
Acurácia do ataque
Classe do ataque

3 - Imprimir os dados de um Pokémon adicionado:
Você deverá ler, na ordem:
Índice do Pokémon no vetor de Pokémon atual.
Imprima os dados do Pokémon na seguinte ordem e formatação:
"Nome do Pokemon: %s\n"
"Tipo primario: %s\n"
"Tipo secundario: %s\n"
"Status:\n"
"\tHP: %d\n"
"\tAtaque: %d\n"
"\tDefesa: %d\n"
"\tAtaque Especial: %d\n"
"\tDefesa Especial: %d\n"
"\tVelocidade: %d\n\n"

4 - Imprimir os dados de um ataque específico de dado Pokémon:
Você deverá ler:
Índice do Pokémon no vetor atual de Pokémon
Índice do ataque no vetor de ataques do Pokémon (0 a 3)
Você então deverá imprimir na seguinte ordem e formatação:
"Nome do Ataque: %s\n"
"Poder base: %d\n"
"Acuracia: %f\n"
"Classe: %c\n\n"

Pode ficar tranquilo, nenhum índice ou dado informado serão inválidos!
*Nenhum nome terá espaço!
Exemplos de entrada

1
Charizard
Fire
Flying
78
130
111
130
85
100
3
0
0

Exemplo de Saída

Nome do Pokemon: Charizard
Tipo primario: Fire
Tipo secundario: Flying
Status:
    HP: 78
    Ataque: 130
    Defesa: 111
    Ataque Especial: 130
    Defesa Especial: 85
    Velocidade: 100

Exemplo de entrada

1
Charizard
Fire
Flying
78
130
111
130
85
100
2
0
0
Flamethrower
90
1.0
s
4
0
0
0

Exemplo de Saída

Nome do Ataque: Flamethrower
Poder base: 90
Acuracia: 1.000000
Classe: s
*/
