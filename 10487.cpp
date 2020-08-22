
/* La complejidad de mi algoritmo es O(n^3), ya que este tiene 3 ciclos anidados
Me lo acepta Uva ya que aunque su compleidad sea muy grande, no supere el O(n!) que es el limite de UVA*/

#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


int main(){
	int n, m,casos = 1;
	while(scanf("%d", &n), n != 0){
		int sums[10000], res[10000];
		for(int i = 0; i < n; i++){
			cin >> sums[i];
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			cin >> res[i];
		}
		printf("Case %d:\n",casos);
		casos++;
		
		for(int i = 0; i < m; i++){
			int temp = 0, clos = 1000000000;
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++){
					if(sums[j] != sums[k]){
						temp = sums[j] + sums[k];
						if(abs(clos - res[i]) >= abs(temp - res[i]))
							clos = temp;
					}
				}
			printf("Closest sum to %d is %d.\n", res[i], clos);
		    }
		
	}
}
