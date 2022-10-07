
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkbfs(int i,vector<int>adj[],vector<int>&color)
{
    color[i]=1;
             for(int neigh:adj[i])
        {
            if(color[neigh]==-1)
            {
             
              color[neigh]=1-color[i]; 
             checkbfs(neigh,adj,color); 
            }
            else if(color[neigh]==color[i])
            return false;
        }
    return true;
}
int main() {
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
         adj[v].push_back(u);
    }
    vector<int>color(n,-1);
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            bool ans=checkbfs(i,adj,color);
            if(ans==true)
            cout<<"Bipartite"<<" ";
            else
            cout<<"Non Bipartite";
        }
    }
    return 0;
}
/*
Input
4 4
1 2 1 3 2 0 3 0  
Output
Bipartite 
*/
