#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){
    string varString;
     int stringLong, casos = 1;

     while(getline(cin, varString)) {
         vector< stack<char> > stackFinal;

         if(varString == "end"){
             break;
         }
         else {
             cout<<"Case "<<casos++ <<": ";
             for(int i=0; i < varString.length(); i++) {
                 int index = -1;
                 bool bnd = false;
                 if(i == 0) {
                     stack<char> x;
                     x.push(varString[i]);
                     stackFinal.push_back(x);
                 }
                 else {
                     for(int j=0;j < stackFinal.size(); j++) {
                         if(stackFinal[j].top() >= varString[i] ) {
                             bnd = true;
                             if (index != -1) {
                                 if(stackFinal[j].top() < stackFinal[index].top()) index = j;
                             }
                             else {
                                 index = j;
                             }
                             
                         }
                     }
                     if(bnd == true) {
                         stackFinal[index].push(varString[i]);
                     }
                     else {
                         stack<char> aux;
                         stackFinal.push_back(aux);
                         stackFinal[stackFinal.size() -1].push(varString[i]);
                     }
                 }
             }
             cout<<stackFinal.size()<<endl;
         }
     }

    return 0;
}