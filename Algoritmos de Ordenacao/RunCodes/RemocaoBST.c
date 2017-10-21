/*

Remoção em BST
Você deve implementar o algoritmo de remoção em uma BST (Binary Search Tree, ou Árvore Binária de Busca, em português), para isso, você precisará primeiro já ter implementado o algoritmo de inserção.

A primeira linha da entrada conterá um número N (N < 10³), que indica o número de inteiros que deverão ser inseridos na BST. A próxima linha conterá N inteiros X (-10⁹ < X < 10⁹), que deverão ser inseridos na BST na ordem em que aparecem. A próxima linha conterá um inteiro M (M < 10³), o número de inteiros que deverão ser removidos. A linha seguinte conterá M inteiros Y (-10⁹ < Y < 10⁹), que devem ser removidos da BST na ordem em que aparecem.

Observe que poderá ser pedida a remoção de um inteiro que não está na BST, nesse caso, não é necessário realizar nenhuma mudança, nem mesmo imprimir qualquer mensagem de erro.

É garantido que não haverão elementos repetidos nos casos de teste.

Para remover um nó, você deve colocar em sua posição seu sucessor imediato, caso ele exista. Caso contrário substitua-o pelo seu antecessor imediato. O link a seguir pode ajudar na compreensão e visualização da remoção: https://visualgo.net/bn/bst

Exemplo de Entrada e Saída
Entrada:

7
10 7 15 3 4 9 8
3
3 12 10 
Saída:

15 7 4 9 8 
Entrada:

4
4 3 7 5
1
4
Saída:

5 3 7 

*/
