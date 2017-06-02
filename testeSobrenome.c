#include <stdio.h>
#include <stdlib.h>

int main(){
	char *aux=NULL, letra;
	int i=0, k=0, count=0;
	char **nomes=NULL;
	
	do{
		nomes= (char**) realloc(nomes, (count+1)*sizeof(char*));
		k=0;
		do{
			letra=getchar();
			aux=(char*) realloc(aux, (k+1)*sizeof(char));
			aux[k]=letra;
			k++;
		}while((letra!='\n') && (letra!='$'));
		aux[k-1] = '\0';
		if(letra=='$'){
			break;
		}
		nomes[count] = (char*) malloc((strlen(aux)+1)*sizeof(char));
		strcpy(nomes[count], aux);
		++count;
	}while(1);
	
	for(i=0; i<count; i++){
		printf("nomes[%d]=%s\n", count, nomes[i]);
	}
	
	
	free(aux);
	return 0;
}
