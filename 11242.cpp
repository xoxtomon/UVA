/*

punto 1 # 11242: tour de france

la complejidad en general de esta solucion es de O(n^2) debido a la funcion ordenar
que es de tipo BubbleSort y por algunos ciclos enlazados que hay en el codigo, sin embargo,
el limite de esta funcion es 100 debido a que el tamaño maximo del arreglo es de 100.

fue aceptada por uva ya que se basa en los limites de esta, por ejemplo se tiene 
en cuenta que la cantidad de platos no puede ser mayor de 10 y cosas asi, y retorna
lo que se pide en esta.

*/

#include <cstdio>
#include <stdlib.h>

void ordenar(double * arr, int n){
	
	bool ordenado = true;
	double aux;
	int j = 0;
	
	while(ordenado){
		ordenado = false;
		j++;
		
		for(int i = 0; i < n - j; i++){
			if(arr[i] > arr[i + 1]){
				
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
				ordenado = true;	
			}
		}	
	}
}

int main(){
	
	int front, rear;
	int fgears[10], rgears[10];
	double ratio[100];
	
	while(scanf("%d", &front), front){
		
		scanf("%d", &rear);
		
		for(int i = 0; i < front; i++)
			scanf("%d", &fgears[i]);
			
		
		for(int i = 0; i < rear; i++)
			scanf("%d", &rgears[i]);
			
		
		int pos = 0;
		for (int i = 0; i < rear; i ++){
			//printf("%d ",rgears[i]);
			for(int j = 0; j < front; j++){		
				//printf("%d ", fgears[j]);
				ratio[pos] = (double)rgears[i] / (double)fgears[j];
				pos ++;
				
			}
		}
		
		/*for(int i = 0; i < pos; i ++)
			printf("%lf ", ratio[i]);*/
		
		ordenar(ratio, pos);
		
		double maximo = -1;
		for(int i = 0; i < pos - 1; i ++){
			
			if(maximo < (ratio[i + 1] / ratio[i]))
				maximo = ratio[i + 1] / ratio[i];
				
			else
				maximo = maximo;
		}
		printf("%.2lf\n", maximo);	
		
		/*for(int i = 0; i < pos; i ++)
			printf("%lf ", ratio[i]);*/
	}
	
	return 0;
}

