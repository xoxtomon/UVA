#include<cstdio>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<bits/stdc++.h> 
using namespace std;

int main(){
	int casos;
	cin>>casos;
	for(int i = 0; i < casos;i++){
		int pisosDisp, aux, cantPisos = 0;
		vector<int> posi,nega, tmp;
		cin >> pisosDisp;
		for(int j = 0; j < pisosDisp; j++){
			cin>>aux;
			/*v1.push_back(aux);
			v2.push_back(aux);*/
			if(aux > 0) posi.push_back(aux);
			else nega.push_back(aux);
		}
		
		sort(posi.begin(),posi.end());
		sort(nega.begin(),nega.end());
		bool bandera;
		
		if(*max_element(posi.begin(),posi.end()) > abs(*min_element(nega.begin(),nega.end()))) bandera = true;
		else bandera = false;
		
		for(int j = 0; j < pisosDisp; j++){
			if(bandera = true){
				if(j = 0){
					cantPisos += 1;
					tmp.push_back(*max_element(posi.begin(),posi.end()));
					posi.erase(max_element(posi.begin(),posi.end()));
					bandera = false;	
				}
				else{
					if(*max_element(posi.begin(),posi.end()) < tmp[j-1]){
						cantPisos += 1;
						tmp.push_back(*max_element(posi.begin(),posi.end()));
						posi.erase(max_element(posi.begin(),posi.end()));
						bandera = false;
					}
					else{
						posi.erase(max_element(posi.begin(),posi.end()));
					}
				}
			}
			else{
				if(j = 0){
					cantPisos += 1;
					tmp.push_back(*min_element(nega.begin(),nega.end()));
					nega.erase(min_element(nega.begin(),nega.end()));
					bandera = true;
				}
				else{
					if(abs(*min_element(nega.begin(),nega.end())) < tmp[j-1]){
					cantPisos += 1;
					tmp.push_back(*min_element(nega.begin(),nega.end()));
					nega.erase(min_element(nega.begin(),nega.end()));
					bandera = true;
					}
					else{
						nega.erase(min_element(nega.begin(),nega.end()));	
					}
				}
			}
		}
		cout<<cantPisos<<endl;
	}
}
