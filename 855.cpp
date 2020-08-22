/*  La complejidad de mi algoritmo es O(n) ya que los unicos ciclos anidados son los 
Sorts, ya lo demas son prints y ciclos para escanear 

por ahora el programa no me lo acepta UVA porque creo que el sort excede el tiempo limite
pero si uso el qsort, este organiza mal la lista, por ende no da bien la respuesta, y ademas lo hice
muy apurado de tiempo, por esnde no la pude resolver bien*/


#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

/*void bsort (int t, int l1[]){
	int temp;
	for(int i = 0; i < t; i++)
		for(int j = 0; j < t; j++){
			if(l1[j] > l1[j+1]){
				temp = l1[j];
				l1[j] = l1[j+1];
				l1[j+1] = temp;
			}
		}
}*/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		
		int n,m,c, street[100000], avenue[10000];
		
		scanf("%d %d %d", &n ,&m ,&c);
		
		for(int i = 0; i < c; i++){
			scanf("%d %d", &street[i],&avenue[i]);
		}
		
		//bsort(c,street);
		//bsort(c,avenue);
		
		qsort(street,c,sizeof(int),cmpfunc);
		
		qsort(avenue,c,sizeof(int),cmpfunc);
		
		
		if(c % 2 == 0){
			cout << "(Street: ";
			cout << street[c/2];
			cout << ", Avenue: ";
			cout << avenue[c/2];
			cout << ")";
			cout << endl;
		}
		
		else{
			cout << "(Street: ";
			cout << street[(c-1)/2];
			cout << ", Avenue: ";
			cout << avenue[(c-1)/2];
			cout << ")";
			cout << endl;
		}
		for(int i = 0 ; i < c; i++){
			street[i] = 0;
			avenue[i] = 0;
		}		
	}
	return 0;
}
