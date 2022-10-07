
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkcycle(int i,vector<int>adj[],vector<int>&vis)
{
    queue<pair<int,int>>q;
    q.push({i,-1});
    vis[i]=1;
    while(!q.empty())
    {
        int front=q.front().first;
        int par=q.front().second;
        q.pop();
        for(int neigh:adj[front])
        {
            if(!vis[neigh])
            {
                q.push({neigh,front});
                vis[neigh]=1;
            }
            else if(par!=neigh)
            return true;
        }
    }
    return false;
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
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool ans=checkcycle(i,adj,vis);
            if(ans==true)
            cout<<"Cycle found"<<" ";
            else
            cout<<"Cycle Not found";
        }
    }
    return 0;
}
/*
Input
3 3
0 1 0 2 1 2
Output
Cycle found 
*/
