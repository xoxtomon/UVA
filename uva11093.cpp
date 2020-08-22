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
	for(int i = 0; i < casos; i++){
		cout<<"Case "<<i+1<<":"<<endl;
		int estaciones,aux;
		cin>>estaciones;
		vector<int> v1, v2;
		for(int j = 0; j < estaciones; j++){
			cin>>aux;
			v1.push_back(aux);
		}
		for(int j = 0; j < estaciones; j++){
			cin>>aux;
			v2.push_back(aux);
		}
		bool bandera = true;
		int acumV1=0, acumV2=0, pos;
		for(int j=0; j < estaciones; j++){
			if(v1[j] >= v2[j]){
				acumV1 += v1[j];
				acumV2 += v2[j];
				pos = j;
			}
			else{
				if(acumV1 >= acumV2){
					acumV1 -= acumV2;
					acumV2 = 0;
					pos = j;
				}
				else{
					bandera = false;
				}
			}
		}
		if(bandera == true) cout<<"Possible from station "<<j<<endl;
		else cout<<"Not possible"<<endl;
	}
}
