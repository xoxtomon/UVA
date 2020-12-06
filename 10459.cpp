#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int n, distMax, nodoMax,rad;
vector<vector<int> > adj(50000);
int grado[50000];
int nivel[50000];
set<int> nodosCentro;
set<int> nodosPeri;

void dfsprof(int v, int padre, int dist){
  int w;
  dist++;
  if(adj[v].size() > 1){
      for(int i = 0; i < adj[v].size(); ++i){
        w = adj[v][i];
        if(w != padre){
          dfsprof(w, v, dist);
        }
      }
  }
  else{
      if(dist == rad){
        nodosPeri.insert(v);
      }
  }
}

void dfsAux(int v, int padre, int dist){
  int w;
  dist++;

  if(dist > distMax){
    distMax = dist;
    nodoMax = v;
  }
  
  for(int i = 0; i < adj[v].size(); ++i){
    w = adj[v][i];
    if(w != padre){
      dfsAux(w, v, dist);
    }
  }
}

int diametro(){
  distMax = 0;
  nodoMax = -1;

  dfsAux(1, -1, -1);
  dfsAux(nodoMax, -1, -1);
  
  return distMax;
}

int radio(){
  int diam = diametro();
  return (diam + 1) / 2;
}

void centro(){
  int i, v, nivelMax = 0, radio, nivelMin=999999999;
  queue<int> cola;

  for(i = 1; i <= n; ++i){
    nivel[i] = 0;
    grado[i] = adj[i].size();
  }

  for(i = 1; i <= n; ++i)
    if(grado[i] == 1)
      cola.push(i);

  while(!cola.empty()){
    v = cola.front();
    cola.pop();

    for(i = 0; i < adj[v].size(); ++i){
      grado[adj[v][i]]--;
      if(grado[adj[v][i]] == 1){
	    cola.push(adj[v][i]);
	    nivel[adj[v][i]] = nivel[v] + 1;
	    nivelMax = max(nivelMax, nivel[adj[v][i]]);
      }
    }
  }

  for(i = 1; i <= n; ++i){
    if(nivel[i] == nivelMax)
      nodosCentro.insert(i);
  }

}

int main(){
    int i, tmp, aux;

    while(scanf("%d", &n)==1){
        /*Clear todos los globales.*/
        nodosCentro.clear();
        nodosPeri.clear();
        for(int i=0;i<50000;i++){
            adj[i].clear();
        }

        for(int i=1;i<=n;i++){
            cin >> tmp;

            for(int j=0;j<tmp;j++){
                cin >> aux;
                adj[i].push_back(aux);
            }
        }

        rad = radio();
        centro();
        cout<<"Best Roots  :";
        for(set<int>::iterator it = nodosCentro.begin();it!=nodosCentro.end();++it){
            cout<<" " <<*it;
            dfsprof(*it,-1,-1);
        }
        cout << endl;

        cout<<"Worst Roots :";
        for(set<int>::iterator it = nodosPeri.begin();it!=nodosPeri.end();++it){
            cout<<" "<<*it;
        }
        cout << endl;
    }
    return 0;
}