#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <algorithm>

using namespace std;

int absMin(string str, int tam){ //Funcion que determina la distanvia minima absoluta de un str.
	int i; 
	int vMin=100000;
	for(i=0;i<tam-1;i++){
		int vAbs = abs(str[i]-str[i+1]);
		vMin = min(vMin,vAbs);
	}
	return vMin;
}

int main(){
	string str, strAux, strFin;
	
	while(getline(cin,str)){
		strAux = str;
		int i;
		int val = -100000;
		int tmp = absMin(str,str.size());
		
		
		if(val<tmp){ //Verifica la permutacion 11 (El input), y establece valores.
			val = tmp;
			strFin = str;
		}
				
		for(i=0;i<10;i++){ //Para verificar las 10 permutaciones anteriores.
			if(prev_permutation(str.begin(),str.end())){
				int aux = absMin(str,str.size());
				if(val < aux){
					val = aux;
					strFin = str;
				}
				if(val == aux){
					strFin = min(strFin,str);
				}
			}
		}
		
		for(i=0;i<10;i++){ //Para verificar las 10 permutaciones siguientes.
			if(next_permutation(strAux.begin(),strAux.end())){
				int aux = absMin(strAux,strAux.size());
				if(val < aux){
					val = aux;
					strFin = strAux;
				}
				if(val == aux){
					strFin = min(strFin,strAux);
				}
			}
		}
		cout<<strFin<<val<<endl;
	}
}
