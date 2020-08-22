#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int maxAbs(int arr[], int n){
	int maxAbs = -1;
	for(int i = 0;i < n; i++){
		if(arr[i] > maxAbs) maxAbs = arr[i];
	}
	return maxAbs;
}

void setTo(int arr[], int n, int x){
	for(int i = 0; i < n; i++){
		arr[i] = x;
	}
}

int main(){
    int gP, pilots, carreras[200][200], puntajes[200], total[200];
	int nroPts, aux, maximo;
	
	
    while (scanf("%d %d",&gP,&pilots) != EOF){
    	if(gP == 0 && pilots == 0) break;
    	
        for (int i = 0; i < gP; ++i){
            for (int j = 0; j < pilots; ++j){
				cin >> carreras[i][j];
				//cout<<carreras[i][j];
			}
		}
		
        cin >> nroPts;
        for (int i = 0; i < nroPts; ++i){
        	
            cin >> aux;
            
            setTo(puntajes,pilots,0);
            for (int j = 0; j < aux; j++){
				cin >> puntajes[j];
				//cout<<puntajes[j];
			}

            setTo(total,pilots,0);
            for (int v = 0; v < gP; v++){
                for (int x = 0; x < pilots; x++){
					total[x] += puntajes[carreras[v][x] - 1];
				}
			}
			
			/*for(int v = 0; v < pilots; v++){
				cout<<total[x]<<" ";
			}*/
			
			
            int bandera = 0;
            maximo = maxAbs(total,pilots);
            for (int j = 0; j < pilots; j++){
                if (total[j] == maximo){
                    if (bandera == 1) cout << ' ';
                    cout << j + 1;
                    bandera = 1;
                }
            }
            cout << '\n';
        }
    }
}
