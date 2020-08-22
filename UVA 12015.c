#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*USUARIO UVA: paulmartinezuva*/
int main(){
	int x, cas, relevancia=0, nro=1;
	scanf("%d",&cas);
	while(cas--){
		char str[100];
		int rel=0;
		printf("Case #%d:\n");
		for(x=0;x<10;x++){
			scanf("%s%d",str,rel);
			if(rel>=relevancia){
				relevancia=rel;
			}
		}
		for(x=0;x<10;x++){
			scanf("%s%d",str,rel);
			if(rel=relevancia){
				printf("%s\n",str);
			}
		}
		nro+=1;
		relevancia=0;
	}
}
