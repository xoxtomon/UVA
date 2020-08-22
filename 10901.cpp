#include<queue>
#include<algorithm>
#include<list>
#include<vector>
#include<utility>
#include<iostream>

using namespace std;

int main(){
	int cas;
	cin>>cas;
	while(cas--){
		queue<int> lft,rgt,final;
		int capF, tiempoF, cantCarros,tmpCarro,horaAct=0;
		char ubq[10];
		
		scanf("%d %d %d",&capF,&tiempoF,&cantCarros);
		for(int i=0;i<cantCarros;i++){
			scanf("%d %s",&tmpCarro,ubq);
			if(ubq == "left")	lft.push(tmpCarro);
			else rgt.push(tmpCarro);
		}
		
		for(int i=1;i<=cantCarros;i++){
			if(i % 0!=0){
				for(int j=0;j<capF;j++){
					if(lft.front()>=horaAct){
						cout<<tiempoF*i<<endl;
						lft.pop();
					}
				}
			}
			else{
				for(int j=0;j<capF;j++){
					if(rgt.front()>=horaAct){
						cout<<tiempoF*i<<endl;
						rgt.pop();
					}
				}
			}
		}
			cout<<endl;
	}
}
