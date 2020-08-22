#include <stdio.h>
/* La complejidad de este algoritmo es O(n^3) 
Está dentro de los límites de UVA puesto que
la parte más compleja de porcesar es muy inferior a O(n^9)
A grosso modo el algoritmo lo que hace es recorrer el arreglo y
va almacenando el valor maximo para una cadena en secuencia, 
cuanto termina retonarna decho valor.
*/
int main() {
	int lon, arr[18],x, casos=1;
	
	while(scanf("%d",&lon)!=EOF){
		int i;
		for(i=0;i<lon;i++){
			scanf("%d",&x);
			arr[i]=x;
		}
		long long mult=0, aux=1;
		int j, w;
		for(j=0;j<lon;j++){
			aux=arr[j];
			if(aux>mult){
					mult = aux;
				}
			for(w=j+1;w<lon;w++){
				aux= aux*arr[w];
				if(aux>mult){
					mult = aux;
				}
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",casos, mult);
		casos+=1;
	}
	return 0;
}
