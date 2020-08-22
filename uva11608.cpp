#include<iostream>

using namespace std;

//La complejidad de este algoritmo es de O(n^2).

int main(){
	int inicial, casos=1;
	
	while(scanf("%d",&inicial) && inicial>=0){
		int i;
		int creados[13], necesitados[13];
		
		creados[0]=inicial;
		
		for(i=1;i<13;i++){
			scanf("%d",&creados[i]);
		}
		
		for(i=0;i<12;i++){
			scanf("%d", &necesitados[i]);
		}
		
		printf("Case %d:\n",casos);
		
		for(i=0;i<12;i++){
			if(inicial >= necesitados[i] ){
				printf("No problem! :D\n");
				inicial -= necesitados[i];
			}
			else{
				printf("no problem. :(\n");
			}
			inicial += creados[i];
		}
		casos +=1;
	}
}

