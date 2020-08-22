#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*USUARIO UVA: paulmartinezuva*/
int main(){
	char str[20];
	int casos=1;
	while(scanf("%s",str)!="#"){
		if (strcmp(str,"HELLO")==0){
			printf("Case %d: %s\n",casos,"ENGLISH");
		}
		else if (strcmp(str,"HOLA")==0){
			printf("Case %d: %s\n",casos,"SPANISH");
		}
		else if (strcmp(str,"HALLO")==0){
			printf("Case %d: %s\n",casos,"GERMAN");
		}
		else if (strcmp(str,"BONJOUR")==0){
			printf("Case %d: %s\n",casos,"FRENCH");
		}
		else if (strcmp(str,"CIAO")==0){
			printf("Case %d: %s\n",casos,"ITALIAN");
		}
		else if (strcmp(str,"ZDRAVSTVUJTE")==0){
			printf("Case %d: %s\n",casos,"RUSSIAN");
		}
		else if(strcmp(str,"#")!=0){
			printf("%s\n","UNKOWN");
		}
		casos+=1;
	}
}
