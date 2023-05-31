#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V);
        
        for(int i=0;i<V;i++)dist[i]=1e9;
        
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgewt=it[1];
                int adjnode=it[0];
                if(dis+edgewt<dist[adjnode]){
                    dist[adjnode]=dis+edgewt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
        // Code here
    }


int main(){
    int n=6;
    cout<<"Total no of nodes : "<<n<<endl;
    
    int e=8;
    cout<<"Total no of edges : "<<e<<endl;


    vector<vector<int>> adj[n];
    vector<vector<int>> edges;
    vector<int> v1{1,4},v2{2,4},v3{0,4},v4{2,2},v5{0,4},v6{1,2},v7{3,3},v8{4,1},v9{5,6},v10{2,3},v11{5,2},v12{2,1},v13{5,3},v14{3,2},v15{2,6},v16{4,3};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
    adj[2].push_back(v7);
    adj[2].push_back(v8);
    adj[2].push_back(v9);
    adj[3].push_back(v10);
    adj[3].push_back(v11);
    adj[4].push_back(v12);
    adj[4].push_back(v13);
    adj[5].push_back(v14);
    adj[5].push_back(v15);
    adj[5].push_back(v16);

    int S=0;
    vector<int> ans;
    ans=dijkstra(n,adj,S);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}