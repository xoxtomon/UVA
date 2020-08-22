#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int valor1,valor2;
	int i, n;
	bool perm = true;
	vector<int> numeros(10);
	for(i=0;i<10;i++){
		numeros[i] = i;
	}
	
	while(cin >> n ){
		if(n == 0){
			break;
		}
		bool found = false;
	//	for(i=0;i<3628800;i++)
		 while(next_permutation(numeros.begin(),numeros.end())){
			valor1 = numeros[0]*10000 + numeros[1]*1000 + numeros[2]*100 + numeros[3]*10 + numeros[4];
			valor2 = numeros[5]*10000 + numeros[6]*1000 + numeros[7]*100 + numeros[8]*10 + numeros[9];
			if ((valor1 % valor2 == 0) && (valor1 / valor2 == n)){
				cout << valor1 <<" "<<"/"<<" "<<valor2<<" "<<"="<<" "<<n<<endl;
				found = true;
			}
		}
		
		if(found == false){
			cout << "There are no solutions for "<<n<<'.'<<endl;
			}
		cout <<endl;
	}
	
}
