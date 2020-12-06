#include <vector>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

vector< vector< pair<int,int> > > adj(10001);
pair<int,int>lejano;
vector<int> visitados(10001,-1);

void dfs(int node, int depth){
    visitados[node] = 1;

    if(lejano.first == 0 and lejano.second==0) lejano = make_pair(node,depth);
    else{
        if(lejano.second < depth) lejano = make_pair(node,depth);
    }

    for(int i=0;i<adj[node].size();i++){
        if(visitados[adj[node][i].first]==-1){
            dfs(adj[node][i].first,depth+adj[node][i].second);
        }
    }
}

int main() {
    string linea;
    stringstream parser;
    int start,end,w;
    int maxNode=-1;
    bool bandera = false;
    vector< vector< pair<int,int> > > restart(10001);

    while(getline(cin,linea)){
        if(linea.size() == 0){
            dfs(1,0);
            fill(visitados.begin(),visitados.end(),-1);
            //lejano = make_pair(lejano.first,0);
            dfs(lejano.first,0);
            cout<<lejano.second<<endl;
            bandera = true;
            
            maxNode=-1;
            adj = restart;
            fill(visitados.begin(),visitados.end(),-1);
            lejano = make_pair(0,0);
        }
        else{
            parser.clear();
            parser << linea;
            parser >> start >> end >> w;

            if(maxNode<start||maxNode<end) maxNode=max(start,end);

            adj[start].push_back(make_pair(end,w));
            adj[end].push_back(make_pair(start,w));
            bandera = false;
        }
    }
    if(!bandera){
        dfs(1,0);
        fill(visitados.begin(),visitados.end(),-1);
        //lejano = make_pair(lejano.first,0);
        dfs(lejano.first,0);
        cout<<lejano.second<<endl;
        adj = restart;
        lejano = make_pair(0,0);
    }
}