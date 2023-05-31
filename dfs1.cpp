#include <bits/stdc++.h>
using namespace std;
bool f = 0;
int d;
vector<int> depth(1000001, 0);
void dfs(int node,vector<vector<int>> adj,bool vis[],vector<int> &ls,int &x){

    vis[node]=true;
    if(node==x && depth[node] <= d){
        f = 1;
        cout<<"Element found :"<<endl;
        ls.push_back(node);
        return;
    }
    ls.push_back(node);
    for(auto it: adj[node]){
        if(f) return;

        if(!vis[it]){
            depth[it] = 1 + depth[node];
            dfs(it,adj,vis,ls,x);
            if(f) return;
        }
        if(f) return;
    }
}

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
    cout<<"Enter depth :" <<endl;
    cin>>d;
    bool vis[n+1]={0};
    int start=1;
    vector<int> ls;
    dfs(start,adj,vis,ls,x);

    if(f){for (auto ele : ls) cout<<ele<<" " ; }
    else{
        cout<<"Not Found"<<endl;
    }
    return 0;

    

}