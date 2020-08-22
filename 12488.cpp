/* Yo pienso que la complejidad de mi algoritmo es O(n^2) ya que hay un doble ciclo dependiente 
UVA no me lo acepta pporque dice que wrong answer, ya que me quedo corto el tiempo para depurarlo bien */


#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


int main(){
	int v1[25], v2[25],n ,pos1 ,pos2;
	// escanea casos
	while(scanf("%d", &n) != EOF){
		// escanea las posiciones iniciales
		for(int i = 0; i < n; i++){
			cin >> v1[i];
		}
		//escanea las posiciones finales
		for(int i = 0; i < n; i++){
			cin >> v2[i];
		}
		
		int res = 0;
		//encuentra las pocisiones iniciales y finales de los vehiculos y los guarda
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (v2[i]==v1[j]){
					pos1 = i;
					pos2 = j;
					break;
				}
			}
			// Va posicion pos posicion contando las cambios de posicion que se hiciero
			for(int m = pos1; m > pos2; m-- ){
				
				v1[m]=v1[m-1];
				res++;
			}
		}
		cout << res;
		cout << endl;
	}
	return 0;
}
