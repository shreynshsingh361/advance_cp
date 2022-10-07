#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void dfs(vector<int>adj[],int i,vector<int>&vis,stack<int>&s)
{
    vis[i]=1;
    for(int neigh:adj[i])
    {
        if(vis[i]==0)
        {
            dfs(adj,neigh,vis,s);
        }
    }
    s.push(i);
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
    vector<int>vis(n,0);
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(adj,i,vis,s);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}
/*
Input
6 6
2 3 3 1 4 0 4 1 5 1 5 2
Output
543210
*/
