#include <iostream>

using namespace std;

int main(){

	int casos, aux, adn[10], platos[50][40];
	scanf("%d\n", &casos);
	char letras[] = {' ', '.', 'x', 'W'};
	 


	while(casos--){

		for(int i = 0; i < 10; i++){
			scanf("%d", &adn[i]);
		}

		/*for(int i = 0; i < 10; i++){
			printf("%d\n", adn[i]);
		}*/

		for(int i = 0; i < 40; i++){
			if(i == 19)
				platos[0][i] = 1;
			else
				platos[0][i] = 0;
		}

		for(int i = 1; i < 50; i++){
			for(int j = 1; j < 39; j++){

			
				aux = platos[i - 1][j - 1] + platos[i - 1][j] + platos[i - 1][j + 1];

				platos[i][j] = adn[aux];

			}

		}

		for(int i = 0; i < 50; i++){
			for(int j = 0; j < 40; j++){

				cout << letras[platos[i][j]];

			}

		}


	}

	return 0;
}