#include<stdio.h>
#include<string.h>

int main(){
	int cas, cuenta = 0,aux;
	char str[10];
	scanf("%d",&cas);
	while(cas--){
		scanf("%s",str);
		if(strcmp("report",str) == 0){
			printf("%d\n",cuenta);
		}
		if(strcmp("donate",str)==0){
			scanf("%d\n",&aux);
			cuenta += aux;
		}
	}
}
