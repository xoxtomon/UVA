/* Pienso que la complejidad de mi algoritmo es de O(n) ya que los ciclos solo son de escaneo y ademas 
de prints, no tiene nada que lo haga de mayor complejidad 
Yo creo que los parametros der UVA lo aceptan por su simplicidad y ademas por su complejidad menor a O(n!)*/

#include<iostream>
#include<cstring>

using namespace std;

int main(){
	
	int casos, v[10000],o;
	char a[1000][200];

	scanf("%d", &casos);
	
	while(casos--){
		int i = 0; 
	
		while(true){
			//scanf("%d", &o);
			cin >> o;
			// Se ponen en la posicion que nos decia el problema números del 0 al o-1
			// Para asi asignales estas posiciones de salida al print
			v[o-1] = i;
			
			if (getchar() == '\n')
			break;
			
			i++;
		}
		
		int j = 0; 
		
		while(true){
			//scanf("%d",&a[j])
			cin >> a[j];
			
			if (getchar() == '\n')
			break;
			
			j++;
		}	
		
		for(int l = 0; l <= i; l++){
			printf("%s\n",a[v[l]]);
		}
		
		if (casos != 0)
			printf("\n");	
			
	}
	return 0;
}
