#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>adj[],vector<int>&vis,int i)
{
    queue<int>q;
    q.push(i);
    vis[i]=1;
    while(!q.empty())
    {
        int a=q.front();
         q.pop();  
        for(int neigh:adj[a])
        {
            if(!vis[neigh])
            {
                q.push(neigh);
                vis[neigh]=1;
            }   
        }
        //cout<<a<<" ";  
    }
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
    vector<int>vis(n,0);
    int c=0;
    for(int i=0;i<m;i++)
    {
        if(vis[i]==0)
        {
            c++;
            bfs(adj,vis,i);
        }
    }
    cout<<c;
    return 0;
}
/*
Input
5 4
0 1 0 2 1 2 3 4
Output
/*
Input
5 4
0 1 0 2 1 2 3 4
Output
2
*/
