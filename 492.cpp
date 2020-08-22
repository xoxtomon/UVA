#include<string>
#include<iostream>
#include<stack>
#include<cstdio>
#include<string.h>
#include<ctype.h>

using namespace std;

/* la complejidad de este algoritmo es de O(n), ya que el unico ciclo funcional que hay es para delimitar cuando la cambia a ser un
valor no alfanumerico, no me lo acepta UVA porque no me quiere identidicar el espacio como un caracter*/

bool esVocal(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; 
}

bool esLetra(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){

	char s;

	while((s = getchar()) != EOF){
		
		stack<char> word;
		
		if(esVocal(s)){ // verifica si es vocal
			string tmp;
			tmp += s;
			while(s = getchar()){
				if (!esLetra(s)){
					break;
				}
		    tmp += s;
			}
			
			cout << tmp+"ay";
		}
			
		else if(isalpha(s)){ // verifica si es una letra 
			string tmp;
			tmp += s;
			while(s = getchar()){
				if (!esLetra(s)){
					break;
				}
		    	tmp += s;
			}
			word.push(tmp[0]);
			tmp.erase(tmp.begin());
			tmp += word.top();
			cout << tmp+"ay";
		}
		
		/*else if(s == 32){
			printf(" ");	
		}*/
		
		else{ // se supone que si no es la una ni la otra deberia ser un espacio, pero no lo lee
			printf("%c",s); 
		}

	}
	return 0;

}
