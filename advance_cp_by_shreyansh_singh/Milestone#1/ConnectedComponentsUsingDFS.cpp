#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>adj[],vector<int>&vis,int i,vector<int>&ans)
{ 
    ans.push_back(i);
    vis[i]=1;
        for(int neigh:adj[i])
        {
            if(!vis[neigh])
            {
                dfs(adj,vis,neigh,ans);
            }   
        }
}
int main() {
    int n,m,u,v;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[i].push_back(v);
    }
    int c=0;
    vector<int>vis(n,0);
    vector<int>ans;
    for(int i=0;i<m;i++)
    {
       
        if(vis[i]==0)
        {
         c++;
        dfs(adj,vis,i,ans);
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
2
*/
