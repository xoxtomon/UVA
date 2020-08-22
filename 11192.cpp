#include <stdio.h>
#include <math.h>
#include <string.h>

/* La complejidad de este algoritmo es O(n**2) si el numero el cual nos dan de los grupos es mayor a 1, si fuera 1 la complejidad seria 
de O(n), y si fuera 0 seria lineal */

int main() {

	char entrada[100],salida[100];
	int num;
	
	while(scanf("%d %s", &num, entrada) && num != 0){
		int j = 0;
		int n = strlen(entrada) / num;
		
		strcpy(salida,entrada);
		
		if(num == strlen(entrada)){
			printf("%s\n",entrada);
		}
		
		else if(num == 1){
			n = strlen(entrada);
			for(int i = 0; i < strlen(entrada); i++){
				salida[n-1] = entrada[i];
				n--;
			}
			printf("%s\n",salida);
		}
			
		else{
			for(int i = 0; i < strlen(entrada); i+= (strlen(entrada) / num)){
				
				while(i < n){
					salida[n-1] = entrada[j];
					j++;
					n--;
				}
				n = n + (2*(strlen(entrada) / num));
			}
			printf("%s\n",salida);
		}

	}
return 0;
}
