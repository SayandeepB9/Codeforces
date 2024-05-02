//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {   
    void dfs(int V,vector<int>* adj,vector<int>& visited, int node, int start, vector<int>& safe)
    {
        if(visited[node]==start)    {visited[node]=-1; return;}
        if(visited[node]!=-2)    return;
        visited[node]=start;
        cout<<"node"<<node<<'\n';
        for(auto i: adj[node])
        {
            dfs(V,adj,visited,i,start,safe);
            if(visited[i]==-1)   visited[node]=-1;
        }
        cout<<"Node"<<node<<visited[node]<<'\n';
        if(visited[node]!=-1)   visited[node]=V,safe.push_back(node);
    }

  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V,-2);
        vector<int> safe;
        vector<vector<int>> parent(V);
        for(int i=0;i<V;i++)
            for(auto j: adj[i]) parent[j].push_back(i);

        for(int i=0;i<V;i++)
        {
            cout<<i<<' '<<visited[i]<<" h\n";
            if(visited[i]!=-2) continue;
            cout<<i<<'\n';
            dfs(V,adj,visited,i,i,safe);
        }
        sort(safe.begin(),safe.end());
        return safe;
    }
};


//{ Driver Code Starts.

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends