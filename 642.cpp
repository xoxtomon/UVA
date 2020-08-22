#include <iostream>
#include <string>
#include <vector>
#include <stack> 
#include <queue> 
#include <fstream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main(){
	string aux;
	map<string,vector<string> > mp;

	for(int i=0; ; i++){
		cin>>aux;
		if(aux == "XXXXXX") break;
		string r = aux;
		sort(aux.begin(), aux.end());
		
		vector<string> tmp (mp[aux]);
		tmp.push_back(r);
		mp[aux] = tmp;
	}
	for(int i = 0; ;i++){
		cin>>aux;
		if(aux == "XXXXXX") break;
		sort(aux.begin(),aux.end());
		
		if(mp.find(aux) == mp.end()){
			cout<<"NOT A VALID WORD\n******"<<endl;
		}
		else{
			vector<string> tmp (mp[aux]);
			for(int j = 0; j < tmp.size(); j++){
				cout<<tmp[j]<<endl;
			}
			cout<<"******"<<endl;
		}
		/*try{
			for(int j = 0; j < tmp.size(); j++){
				cout<<tmp[j]<<endl;
			}
			cout<<"******"<<endl;
		}
		catch (){
			out_of_range("NOT A VALID WORD\n******\n");
		}*/
	}
}
