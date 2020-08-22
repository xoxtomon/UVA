#include<stdio.h>
#include<math.h>

int main(){
	int cas;
	long long int filas, nroG;
	scanf("%d", &cas);
	while(cas--){
		int i = 1;
		scanf("%lld",&nroG);
		filas = sqrt(1+8*nroG) -1;
		printf("%lld\n", filas / 2);
	}
	
}
