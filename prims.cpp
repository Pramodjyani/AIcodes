#include<bits/stdc++.h>
using namespace std;

#define V 5

void printmst(int parent[V], int graph[V][V]){
    cout<<"Edge \tWeight\n";
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
}

int minkey(int key[V],bool mst[V]){
    int min=INT_MAX;
    int min_ind;
    for(int i=0;i<V;i++){
        if(mst[i]==false&&key[i]<min){
            min=key[i];
            min_ind=i;
        }
    }
    return min_ind;
}

void prims(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mst[V];

    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mst[i]=false;
    }
    parent[0]=-1;
    key[0]=0;

    for(int c=0;c<V-1;c++){
        int u=minkey(key,mst);

        mst[u]=true;

        for(int v=0;v<V;v++){
            if(graph[u][v]&&mst[v]==false&&graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }

    }
    printmst(parent,graph);
}


int main(){
    
    int graph[V][V]={ { 0, 2, 0, 6, 0 },
                      { 2, 0, 3, 8, 5 },
                      { 0, 3, 0, 0, 7 },
                      { 6, 8, 0, 0, 9 },
                      { 0, 5, 7, 9, 0 } };

    prims(graph);

    return 0;                  
}