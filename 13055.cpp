/*

problema #13055 inception:

Este programa tiene una complejidad lineal debido a que depende del numero de casos cuyo maximo es 10000.

hace un ciclo que se repite el numero de casos que haya.

*/


#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){

	int casos;
	stack<string> dream;
	string aux, act;

	scanf("%d", &casos);

	casos--;

	while(casos--){

		cin >> act;

		if(act == "Sleep"){

			cin >> aux;
			dream.push(aux);

		}
		else if(act == "Kick"){

			if(!dream.empty())
				dream.pop();

		}
		else{

			if(dream.empty()){

				cout << "Not in a dream" << endl;

			}else{

				cout << dream.top() << endl;

			}

		}

	}


	return 0;
}