
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkbfs(int i,vector<int>adj[],vector<int>&color)
{
    queue<int>q;
    q.push(i);
    color[i]=1;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
             for(int neigh:adj[front])
        {
            if(color[neigh]==-1)
            {
             
              color[neigh]=1-color[front]; 
               q.push(neigh); 
            }
            else if(color[neigh]==color[front])
            return false;
        }
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
