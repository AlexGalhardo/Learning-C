/*
Biblioteca (trabalhoso :'{ )
Disciplina: SSC0502 - Laboratório de Introdução a Computação I
Prazo de Entrega: 06/07/2017 23:59:59 Fechado

Certo tempo, havia uma biblioteca chamada Libinfinity, que começou pequena, mas foi crescendo com o tempo. Hoje, ela está uma biblioteca formidável com bastantes livros. Porém, justamente por ter crescido, a gerência e o controle dos livros foi se tornando mais complexa. Portanto, esta biblioteca contratou você para organizar um sistema para ela.

Você terá que cumprir diversas tarefas que incluem:

    Cadastro: você receberá dados de um livro e deverá criar um livro de acordo com os dados recebidos e incluí-lo na coleção de livros cadastrados da biblioteca, para que ele se torne disponível para consulta futuramente. Os dados que um livro possui estão documentados mais abaixo, depois da listagem de tarefas que você deve cumprir; o único dado que você não deve receber para cadastrar um livro será a sua situação, a qual deve ser inicializada como disponível.

    Listagem de livros: você deve exibir os dados de todos os livros na da coleção de livros cadastrados na biblioteca. Essa exibição deve ser impressa na ordem do sistema, que corresponde à ordem que os livros foram cadastrados. A ordem do sistema muda quando ocorre uma ordenação. Porém, se mais livros forem inseridos após a ordenação, a ordem do sistema considera os livros anteriores ordenados, e os posteriores, na ordem que foram inseridos. Há um exemplo explicando como essa ordem de sistema funciona ao final dessa especificação.

    Contagem de livros: você deve exibir o número de livros na coleção de livros cadastrados.

    Consultar por título: você receberá o título de um livro, e deve consultar esse livro na coleção de livros cadastrados, exibindo seus dados se o livro for encontrado, ou um aviso se não for.

    Consultar por autor: você receberá o nome de autor de livros, e deve consultar a coleção de livros cadastrados e imprimir dados dos livros escritos por este autor;

    Empréstimo / devolução: você receberá o título de um livro, e deve alterar a situação dele se ele existir na coleção de livros cadastrados, ou não fazer nada se o livro não existir.

    Ordenação: você deve alterar a ordem do sistema de forma a ordenar alfabeticamente os livros cadastrados. Se uma listagem for solicitada logo após uma ordenação, os livros serão impressos em ordem alfabética. A ordenação só deve ser realizada quando solicitada, e se livros forem cadastrados após a ordenação, eles deverão ser colocados após os livros ordenados, na ordem em que forem inseridos; a nova coleção de livros cadastrados, que inclui os livros novos, só estará totalmente ordenada se outra operação de ordenação for solicitada.

    Os dados que serão armazenados à respeito dos livros serão:
    Título (máximo de 64 caracteres);
    Autor (máximo de 64 caracteres);
    Editora (máximo de 64 caracteres);
    Ano de lançamento;
    Situação (emprestado / disponível).

    A biblioteca lhe informou que você pode assumir algumas hipóteses que podem, potencialmente, facilitar seu trabalho:
    Cada livro terá apenas um exemplar. Dessa forma, emprestar um livro torna-o indisponível até sua devolução.
    Não haverá livros com mesmo título, sendo o título dos livros o único critério usado na ordenação.
    A biblioteca possui uma fonte infinita de energia para manter o computador ligado, sendo que os livros podem ser cadastrados apenas em memória RAM. Agora, como a biblioteca tem energia infinita é o mistério da questão. :P

    Mas, você tem algumas restrições impostas pelo seu exigente chefe:
    A estrutura usada para armazenar os livros deve estar em memória heap;

    Ajude a biblioteca!

    Entrada:
    A entrada consiste de um código inteiro, que corresponde a uma operação a ser realizada pelo sistema de acordo com a lista abaixo:
    Cadastro;
    Listagem de livros;
    Contagem de livros;
    Consulta por título;
    Consulta por autor;
    Empréstimo / devolução;
    Ordenação;
    Sair do sistema;
    Demais códigos: operação inválida.

    Entradas adicionais poderão serão fornecidas de acordo com o código lido:

    Cadastro: você deve ler três strings (de no máximo 64 caracteres), correspondentes, respectivamente, ao título, autor e editora e um inteiro correspondente ao ano de lançamento do livro a ser adicionado.

    Listagem de livros: não haverá entradas adicionais.

    Contagem de livros: não haverá entradas adicionais.

    Consulta por título: você deve ler uma string (de no máximo 64 caracteres) correspondente ao título do livro a ser consultado.

    Consulta por autor: você deve ler uma string (de no máximo 64 caracteres) correspondente ao autor do livro a ser consultado.

    Empréstimo / devolução: você deve ler uma string (de no máximo 64 caracteres) correspondente ao título do livro a ser emprestado / devolvido.

    Ordenação: não haverá entradas adicionais.

    Sair do sistema: não haverá entradas adicionais.

    Demais códigos: operação inválida: não haverá entradas adicionais.

    Após ler as entradas, processá-las e exibir as saídas correspondentes, se o código recebido anteriormente não for zero (isto é, se não foi solicitada uma operação de sair do sistema), você deve voltar a ler o código e as entradas adicionais e repetir o algoritmo. Essa repetição ocorrerá até que o código zero for recebido, ou seja, até se desejar sair do sistema. Nesse caso, processe a operação, exiba a saída correspondente e encerre o programa.

    Saída:
    (Para facilitar a compreensão, a mensagem a ser impressa entre barras verticais, ou seja, se a a saída for |saida| imprima a palavra saida. Além disso, o conteúdo entre <> deve ser substituído pelo devido valor. Assim, uma saída |\n| deve imprimir o nome adequado seguido de '\n'. Por último, o símbolo <...> implica indução, isto é, |<...>| indica que você deve imprimir mensagens apropriadas de 1 a N).

A impressão do livro, quando solicitada pelas outras tarefas, deve ser feita da seguinte forma:
|Titulo: \nAutor: \nEditora: \nAno de lancameno: \nSituacao: \n|,
Sendo que é avaliada em "disponivel" se o livro não estiver emprestado, ou "emprestado" se estiver emprestado.

Imprima as seguintes mensagens, de acordo com as tarefas e os possíveis cenários:

    Cadastro:
    1.1. Não imprima nada para cadastro.

    Listagem de livros:
    2.1. Se a biblioteca possuir N livros cadastrados: |<...>|;
    2.2. Se a biblioteca não possuir livros cadastrados, não imprima nada.

    Contagem de livros:
    3.1. Cenário único: |TAMANHO = \n|.

    Consulta por título:
    4.1. Se o livro for enconrado: ||;
    4.2. Se o lviro não for encontrado: |NAO ENCONTRADO\n|.

    Consulta por autor:
    5.1. Se o autor possuir N livros cadastrados: |<...>|;
    5.2. Se o autor não possuir nenhum livro cadastrado, não imprima nada.

    Empréstimo / devolução:
    6.1. Se o livro estiver sendo emprestado: |EMPRESITMO\n|;
    6.2. Se o livro estiver sendo devolvido: |DEVOLUCAO\n|;
    Obs.: na impressão dos dois itens anteriores, você deve imprimir a situação do livro após o empréstimo / devolução.
    6.3. Se o livro não existir: |LIVRO NAO CADASTRADO\n|.

    Ordenação:
    7.1. Cenário único: Não imprima nada para ordenação.

    Operação inválida:
    8.1. Cenário único: Não imprima nada para operação inválida.

    Sair do sistema:
    9.1. Cenário único: Não imprima nada quando for sair.

Exemplo de armazenamento da lista de livros na memória, e eventuais ordenações dessa lista:
(L: lista de livros cadastrados na ordem do sistema; somente será mostrado o título dos livros nesse exemplo, para faciliar a compreensão.)

    Início do programa:
    L: (Vazia)

    Inserção do livro de título "F":
    L: F

    Inserção do livro de título "J":
    L: F J

    Inserção do livro de título "C":
    L: F J C

    Ordenação:
    L: C F J

    Inserção do livro de título "A":
    L: C F J A

    Inserção do livro de título "H":
    L: C F J A H

    Ordenação:
    L: A C F H J

Dica:
Está disponível no run.codes um código começado para a implementação deste trabalho.
Você pode terminá-lo, mas não precisa. Pode começar um código a partir do zero, se assim preferir.
Se optar por terminar o código, por favor, leia os comentário iniciais, que ajudarão a entender o código.

(Exercício retirado da disciplina SCC0221 - Introdução a Ciência da Computação, 2015)
*/








#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 
 * SECAO DE COMENTARIOS INICIAIS
 * 
 * Sady Sell Neto - ICMC - USP
 * (C) Copyright 2015
 *
 * APAGUE ESTA SECAO INTEIRA ANTES DE ENTREGAR SEU CODIGO!!!
 * 
 * Este codigo ja possui algumas estruturas e funcoes declaras, mas nenhuma
 * implementada. 
 * Voce possui uma documentacao que cita a ideia geral de cada funcao, mas
 * voce deve implementa-las. A documentacao aqui presente eh so uma ideia do
 * que cada funcao deve fazer; ela eh insuficiente para a compreensao de um
 * codigo completo, e portanto, as funcoes devem ser re-documentadas e
 * comentadas para a entrega.
 * Lembre-se que pode implementa-las como quiser, desde que a colecao de
 * livros encontre-se em memoria heap.
 * 
 * Isto nao significa que, os livros em si, devem ser ponteiros para regiao
 * da heap com eles alocados. Os livros poderao ser alocados automaticamente,
 * mas a colecao deles deve ser alocada dinamicamente. Isto nao significa que
 * voce nao pode fazer os livros em si serem ponteiros. Fica a seu criteiro
 * usar a alocacao automatica ou dinamica para os livros.
 * 
 * As funcoes estao declaras apenas em seu prototipo, usando o que conhece-se
 * por "forward declaration", que consiste em declarar apenas o cabecalho da
 * funcao, e definir seu comportamento mais adiante no codigo. Ha um exemplo
 * nesta secao de como proceder com funcoes declaradas com forward
 * declaration.
 * 
 * Variavel size_t: a semantica da variavel size_t eh representar um tipo
 * integral que representa um tamanho.
 * Note que nao ha necessidade de usar esse tipo de variavel. Se optar por
 * usa-la e necssitar imprimi-la, a mascara de printf para este tipo de
 * variavel eh: %zu.
 * Exemplo: printf("%zu", variavel_size_t);
 * 
 * Exemplo de forward declaration:
 * 
 * // A funcao square nao sera usada para nada no codigo.
 * // Ela esta neste codigo apenas para o exemplo.
 * int square(int x); // Forward declaration da funcao square.
 * // Mais adiante no codigo, implementa-se a funcao square:
 * // ...
 * int square(int x) { // Implementacao da funcao square:
 *     return x * x;
 * }
 * // Sim, voce re-declara a funcao declarada com forward declaration para
 * // implementa-la, como no exemplo.
 * 
 * Documentacao do codigo comecado:
 * Perceba que os parâmetros chamados "this" correspondem a estrutura a ser
 * manipulada.
 * 
 * Estrutura Book: estrutura para armazenar um livro.
 * Funcoes que manipulam a estrutura Book:
 * 
 * B1. Book_intialize: inicializa uma estrutura Book, dados seus conteudos;
 *   Sugere-se que a alocao dinamica de memoria necessaria para o uso de
 *   uma estrutura Book seja feita nesta funcao. Se nao houver necessidade
 *   de alocacao de memoria, essa funcao deve realizar uma simples atribuicao
 *   de conteudo.
 * Parametro this: estrutura a ser inicializada;
 * Parametro title: titulo do livro a ser inicializado;
 * Parametro author: autor do livro a ser inicializado;
 * Parametro editor: editora do livro a ser inicializado;
 * Parametro release_year: ano de lancamento a ser inicializado
 * Retorno: nao ha.
 *
 * B2. Book_copy: copia o conteudo de uma estrutra Book para outra.
 * Parametro this: estrutura que tera seu conteudo reescrito, substituido pela 
 *   outra.
 * Parametro x: estrutura que tera seu conteudo copiado, isto eh, a fonte da
 *   copia.
 * Retorno: a estrutura this modificada.
 * (Essa funcao modifica a estrutura, e retorna-a tambem. Ela nao precisaria
 * de retorno, assim, como a strcpy nao precisaria, pois o proprio argumento
 * eh modificado. Mas, existem situacoes, que eh conveniente retornar o
 * proprio argumento.)
 *
 * B3. Book_rent: altera a situacao (emprestado / disponivel) de um estrutra
 *   Book.
 * Parametro this: livro que tera sua situacao modificada.
 * Retorno: a estrutura this modificada.
 * (Essa funcao modifica a estrutura, e retorna-a tambem. Ela nao precisaria
 * de retorno, assim, como a strcpy nao precisaria, pois o proprio argumento 
 * eh modificado. Mas, existem situacoes, que eh conveniente retornar o
 * proprio argumento.)
 * 
 * B4. Book_compare: compara alfabeticamente o titulo duas estruturas Book.
 * Parametro lhs: um dos livros a ser comparado.
 * Parametro rhs: o outro livro a ser comparado.
 * Retorno: um inteiro de acordo com o resultado da comparacao:
 *   0: se os titulos dos argumentos sao iguais;
 *   <0: se o titulo de lhs vier antes na ordem alfabetica do que o titulo de rhs;
 *   >0: se o titulo de lhs vier depois na ordem alfabetica do que o titulo de rhs.
 * 
 * B5. Book_swap: troca o conteudo de duas estruturas book.
 * Parametro x: uma das estruturas a ter seu conteudo trocado.
 * Parametro y: a outra estrutura a ter seu conteudo trocado.
 * Retorno: nao ha.
 * 
 * B6. Book_print: imprime o conteudo de um livro na saida padrao.
 * Parametro this: livro a ter seu conteudo impresso.
 * Retorno: nao ha.
 * 
 * B7. Book_finalize: finaliza um livro, isto eh, desaloca a memoria
 *   dinamicamente alocada para uma estrutura Book. Se esta estrutura nao
 *   aloca memoria dinamicamente, esta funcao pode ser descartada.
 * Parametro this: estrutura a ter sua memoria liberada;
 * Retorno: nao ha.
 *
 * Estrutura Library: estrutura para armazenar a colecao de livros da
 * biblioteca.
 * Funcoes que manipulam a estrutura Library:
 *
 * L1. Library_initialize: inicializa uma estrutura Library. Sugere-se que a
 *   alocao dinamica de memoria necessaria para o uso de uma estrutura Library
 *   seja feita nesta funcao. Se nao houver necessidade de alocacao de memoria,
 *   esta funcao pode ser descartada.
 * Parametro this: estrutura a ser inicializada.
 * Retrono: nao ha.
 *
 * L2. Library_size: obtem o tamanho de uma biblioteca, isto eh, o numero de
 *   livros cadastrados.
 * Parametro this: biblioteca cujo tamanho sera obtido.
 * Retorno: tamanho obtido.
 * 
 * L3. Library_find: procura um livro por titulo na biblioteca.
 * Parametro this: biblioteca onde o livro sera procurado.
 * Parametro title: titulo do livro a ser procurado.
 * Retorno: ponteiro para o livro encontrado ou NULL se o livro nao for
 *   encontrado.
 *
 * L4. Library_find_by_author: procura livros na biblioteca por autor. Os
 *   livros encontrados tem seus dados impressos, ao inves de serem retornados.
 * Parametro this: biblioteca onde os livros serao procurados.
 * Parametro author: autor cujos livros serao procurados;
 * Retorno: nao ha.
 *
 * L5. Library_add: adiciona / cadastra um livro na biblioteca.
 * Parametro this: biblioteca a ter sua colecao expandida.
 * Parametro x: livro a ser adicionado.
 * Retorno: nao ha.
 * 
 * L6. Library_sort: ordena por titulo os livros cadastrados em uma estrutura
 *   Library.
 * Parametro this: biblioteca a ser ordenada.
 * Retorno: a estrutura this ordenada.
 * (Essa funcao modifica a estrutura, e retorna-a tambem. Ela nao precisaria
 * de retorno, assim, como a strcpy nao precisaria, pois o proprio argumento
 * eh modificado. Mas, existem situacoes, que eh conveniente retornar o
 * proprio argumento.)
 *
 * L7. Library_print: imprime os livros contidos na biblioteca, na ordem em
 *   que estao na memoria.
 * Parametro this: biblioteca a ter seus livros impressos.
 * Retorno: nao ha.
 *
 * L8. Library_finalize: finaliza uma biblioteca, isto eh, desaloca a memoria
 *   dinamicamente alocada para uma estrutura Library. Se esta estrutura nao
 *   aloca memoria dinamicamente, esta funcao pode ser descartada.
 * Parametro this: estrutura a ter sua memoria liberada;
 * Retorno: nao ha.
 *
 * Tenha um bom trabalho! ;)
 * 
 * FIM DA SECAO DE COMENTARIOS INICIAS
 */

typedef struct {
} Book;

void Book_initalize(Book* this, const char* title, const char* author, const char* editor, const int release_year);
Book* Book_copy(Book* this, const Book* x);
Book* Book_rent(Book* this);
int Book_compare(const Book* lhs, const Book* rhs);
void Book_swap(Book* x, Book* y);
void Book_print(const Book* this);
void Book_finalize(Book* this);

typedef struct {
} Library;

void Library_initialize(Library* this);
size_t Library_size(const Library* this);
Book* Library_find(const Library* this, const char* title);
void Library_find_by_author(const Library* this, const char* author);
void Library_add(Library* this, const Book* x);
Library* Library_sort(Library* this);
void Library_print(const Library* this);
void Library_finalize(Library* this);

int main(int argc, char* argv[]) {
	return 0;
}

