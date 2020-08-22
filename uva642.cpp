#include <iostream>
#include <string>
#include <vector>
#include <stack> 
#include <queue> 
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<string> dic, dic_ord, des;
	string aux;
	int cant = 0;
	
	for(int i = 0; ; i++){
		cin >> aux;
		if(aux == "XXXXXX") break;
		dic.push_back(aux);
		sort(aux.begin(),aux.end());
		dic_ord.push_back(aux);
		cant++;
	}
	for(int i = 0; ; i++){
		bool bnd = false;
		cin >> aux;
		if(aux == "XXXXXX") break;
		sort(aux.begin(),aux.end());
		//cout<<aux;
		
		for(int j = 0; j < cant; j++){
			//cout<<"LLEGUÉ"<<endl;
			if(dic_ord[j] == aux){
				cout<<dic[j]<<endl;
				bnd = true;
				cout<<"******"<<endl;
			}

		}
		if(bnd == false) cout<<"NOT A VALID WORD"<<"\n"<<"******"<<endl;
		
	}
	/*for(int i = 0 ; i < dic.size(); i++ ){
		cout<<"sin organizar: "<<dic[i]<<endl;
		cout<<"Organizado: "<<dic_ord[i]<<endl;
	}*/
}
