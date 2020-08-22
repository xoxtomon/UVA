#include <stdio.h>
#include <string.h>
/*
La complejidad del algoritmo de de O(n^2)
Uva lo acepta porque no rebasa los límites.
Generalmente lo que hace el algoritmo es almacenar una cadena,
convertir a enteros evaluar los operadores y deacuerdo a si es
maximo o minimo se establece el orden de operaciones.
*/
int main(){
	int n, i=0;
	char cad[100];
	scanf("%d",&n);
	while(i<n) {
        scanf("%s", cad);
        long long maximo[100], minimo[100], aux = 0;
        int j, pos1 = 0, pos2 = 0, len;
        len = strlen(cad);
        char operador = '+';
        for(j = 0; j <= len; j++) {
            if(cad[j] >= '0' && cad[j] <= '9')
                aux = aux*10 + cad[j]-'0'; 
			else {
                if(operador == '+') {
                    if(pos1 == 0)
                        maximo[pos1++] = aux;
                    else
                        maximo[pos1-1] += aux;
                    minimo[pos2++] = aux;
                } 
				else {
                    if(pos2 == 0)
                        minimo[pos2++] = aux;
                    else
                        minimo[pos2-1] *= aux;
                    maximo[pos1++] = aux;
                }
                operador = cad[j], aux = 0;
            }
        }
        long long valMax = 1, valMin = 0;
        for(j = 0; j < pos1; j++)
            valMax *= maximo[j];
        for(j = 0; j < pos2; j++)
            valMin += minimo[j];
        printf("The maximum and minimum are %lld and %lld.\n", valMax, valMin);
        i+=1;
    }
	return 0;
}


