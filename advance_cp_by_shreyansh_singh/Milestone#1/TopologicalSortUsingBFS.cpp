#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void bfs(vector<int>adj[],int N)
{      queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
     for (int i = 0; i < topo.size(); i++)
        cout << topo[i] << " ";
}
int main() {
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bfs(adj,n);
    return 0;
}/*
Input
6 6
2 3 3 1 4 0 4 1 5 1 5 2
Output
4 5 0 2 3 1 
*/
