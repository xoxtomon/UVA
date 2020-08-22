#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <iterator>
using namespace std;

int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		int guess;
		scanf("%d",&guess);
		vector<int> codigo, corr, corrMalpos
		while(guess--){
			int code, digCorr, digPos;
			scanf("%d %d/%d",&code, &digCorr, &digPos);
			codigo.push_back(code);
			corr.push_back(digCorr);
			corrMalpos.push_back(digPos);
		}
		
	}
}
