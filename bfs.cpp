#include <bits/stdc++.h>
using namespace std;
bool f=false;


int main(){
    vector<vector<int>> adj;
    int n;
    cout<<"ENter no of nodes";
    cin>>n;
    adj.resize(n+1);
    cout<<"enter no of edges";

    int e;
    cin>>e;
    while(e--){
        int u;
        int v;
        cout<<"enter edges";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x;
    cout<<"find :"<<endl;
    cin>>x;
    bool vis[n+1]={0};
    vis[1]=true;

    queue<int>q;
    q.push(1);
    vector <int> bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        if(node==x){
            f=true;
            cout<<"Element found :"<<endl;
            for(auto it:bfs){
                cout<<it<<" ";
            }
            break;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=true;
                q.push(it);
            }

        }
    }
    if(f==false){
        cout<<"Element not found";
    }

    return 0;

    

}