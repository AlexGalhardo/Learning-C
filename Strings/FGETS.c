#include <stdio.h>
#include <stdlib.h>

/*
BUGS
Never use gets(). Because it is impossible to tell without knowing the data
in advance how many characters gets() will read, and because gets() will
continue to store characters past the end of the buffer, it is extremely
dangerous to use. It has been used to break computer security. Use fgets()
instead.
*/

int main(){

    char name[100];
    fgets(name, 100, stdin);

    //gets(name); // NUNCA USE gets()

    printf("%s\n", name);

    return 0;
}
