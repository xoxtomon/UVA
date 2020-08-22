#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

//La complejidad de este algoritmo es de O(n^2) hasta ahora.

int main(){
	string tmp[100], codigo[100], pais[100], precio[100];
	
	int i=0;
	
	while(scanf("%s",tmp)){
		if(tmp=="000000"){
			break;		
		}
		
		string codVal,tmpCodigo, tmpPais, del1=" ",del2="$",del3="\n";
		tmpCodigo = tmp.substr(0,tmp.find(del1));
		tmpPais = tmp.substr(tmp.find(del1)+1,(tmp.find(del2)-tmp.find(del)-1));
		tmpcodVal = tmp.substr(tmp.find(del2)+1,(tmp.find(del3)-tmp.find(del2)-1));
		
		codigo[i] = tmpCodigo;
		pais = tmpPais;
		precio[i] = tmpcodVal;
		
		i++;
	}
	
	string aux;
	while(cin>>aux){
		int j;
		if(aux=="#"){
			break;
		}
		int error = 1;
		string tmpCod, tmpDur, tmpRev, del1=" ";
		tmpCod=aux.substr(0,aux.find(del1));
		tmpRev=aux;
		reverse(tmpRev.begin(),tmpRev.end());
		tmpDur = tmpRev.substr(0,tmpRev.find(del1));
		reverse(tmpDur.begin(),tmpDur.end());
		
		if(tmpCod[0]!='0'){
			printf("%-16s%-15s%20s%5d  0.00   0.00\n",tmpCod.c_str(),"Local",
													tmpCod.c_str(),tmpDur.c_str());
		}
		
		for(j=0,j<i;j++){
			double cost;
			string codAux;
			if(codigo[j]==tmpCod.substr(0,codigo[j].size()-1)){
				error = 0;
				cost = atoi(precio[j])*atoi(tmpDur);
				codAux = tmpCod.substr(codigo[j].size(),tmpCod.size()+1);
				printf("%-16s%-25s%10s%5d%6.2lf%7.2lf\n",tmpCod.c_str(),pais[j].c_str(),
													codAux.c_str(),tmpDur.c_str(), cost );
			}
		}
		if(error){
			printf("%-16s%-25s%21d%7.2lf\n", tmpCod.c_str(), "Unknown", tmpDur.c_str(), -1.00);
		}	
	}
	
}
