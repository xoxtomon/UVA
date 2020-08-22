#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <iterator>
using namespace std;

int main(){
	int i,cas, posMenor, posMayor;
	cin>>cas;
	vector<string> nom;
	vector<int> fecha;
	for(i=0;i<cas;i++){
		char n[15];
		int d, m , a, tmp;
		scanf("%s",&n);
		scanf("%d %d %d", &d, &m,&a);
		/*if(m>9){
			tmp = a*100 +m ;
		}
		else{
			tmp = a * 100 + m;
		}
		if(d>9){
			tmp = tmp * 100 + d;
		}
		else{
			tmp = tmp * 100 +d;
		}*/
		tmp = (a*100 + m)*100 + d;
		fecha.push_back(tmp);
		nom.push_back(n);
	}
	
	vector<int>::iterator it = min_element(fecha.begin(),fecha.end());
	vector<int>::iterator it2 = max_element(fecha.begin(),fecha.end());
	
	posMenor= it2 - fecha.begin();
	posMayor= it - fecha.begin();
	
	cout<<nom[posMenor]<<endl;
	cout<<nom[posMayor]<<endl;

}
