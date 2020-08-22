#include<queue>
#include<algorithm>
#include<list>
#include<vector>
#include<utility>
#include<iostream>

// la complejidad del algoritmo seria en el peor caso O(n^2)
using namespace std;

int main(){
	int cas, aux;
	
	cin>>cas;
	while(cas--){
		int trabajos, pTrabajo; 
		int t = 0;
		vector<int> vec;
		cin>>trabajos;
		cin>>pTrabajo;
		
		queue<int> col, pCol;
		for(int i = 0; i < trabajos; i++){
			col.push(i);
			cin>>aux;
			pCol.push(aux);
			vec.push_back(aux);
		}
		sort(vec.begin(),vec.end());
		
		bool bandera = true;
		while(bandera == true){
			
			int elem = col.front();
			int prio = pCol.front();
			
			col.pop();
			pCol.pop();
			
			if(vec[vec.size() - 1] == prio){
				if(elem == pTrabajo){
					cout<<t+1<<endl;
					bandera = false;
				}
				else{
					t++;
					vec.pop_back();
				}
			}
			else{
				col.push(elem);
				pCol.push(prio);
			}
		}
	}
}
