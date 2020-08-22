#include<string>
#include<iostream>
#include<stack>
#include<cstdio>
#include<string.h>
#include<ctype.h>

using namespace std;
 
 /*Si hubieramos optimizado de mejor manera nuestro tiempo y lograramos realizar a cabalidad el problema, lo podriamos haber resuelto en O(n^3/2)*/
 
int main(){
	
	list<stack<string> > card;
	string c;
	vector<string> vec;
	bool terminado = true;
	
	while(terminado == true){
		for(int i = 0; i < 52; i ++){
			cin >> c;
			if(c == '#'){
				terminado = false;
			}
			vec.push_back(c)
		}
	}
	return 0;
}
