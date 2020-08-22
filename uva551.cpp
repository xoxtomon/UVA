#include <iostream>
#include <string>
#include <vector>
#include <stack> 
#include <queue> 
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

string contrario(string str){
	if(str == ")") return "(";
	if(str == "]") return "[";
	if(str == "}") return "{";
	if(str == ">") return "<";
}

int main(){
	string aux;
	while(getline(cin,aux)){
		string tmp = aux;
		stack<string> open;
		int pos = 0, cas = 0;
		bool bandera = true;
		
		for(int i = 0; i < aux.length(); i++){
			cout<<aux[i]<<endl;
			if(aux[i] == ')' && i == 0 ){
				cout<<"NO 0"<<endl;
				bandera == false;
				cas == -1;
				break;
			}
			if(aux[i] == '('){
				if(aux[i+1] == '*'){
				string tmp = "(*";
				open.push(tmp);	
				}
				else{
					string j = "(";
					open.push(j);
				}
			}
			if(aux[i] == '[' || aux[i] == '{' || aux[i] == '<'){
				string j(1,aux[i]);
				open.push(j);
			}
			if(aux[i] == '*'){
				if(aux[i+1] == ')' && aux[i-1] != '('){
					if(!open.empty()){
						if(open.top() == "(*") open.pop();
					}
					else {
						bandera == false;
						break;
					}
				}
			}
			if(aux[i] == ')'||aux[i] == ']'||aux[i] == '}'||aux[i] == '>'){
				string j(1,aux[i]);
				if(!open.empty()){
					if(open.top() == contrario(j)) open.pop();
				}
				else{
					bandera == false;
					break;
				}
			}
			else{
				pos++;
			}
		}
		if(!open.empty() && bandera == false && cas != -1){
			cout<<"NO "<<pos-1<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
}
