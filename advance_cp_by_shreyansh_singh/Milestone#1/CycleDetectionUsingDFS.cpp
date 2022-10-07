
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
bool checkcycle(int i,int &par,vector<int>adj[],vector<int>&vis)
{
    vis[i]=1;
        for(int neigh:adj[i])
        {
            if(!vis[neigh])
            {
                checkcycle(neigh,i,adj,vis);
            }
            else if(par!=neigh)
            return true;
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
    }
    vector<int>vis(n,0);
    int par=-1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool ans=checkcycle(i,par,adj,vis);
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
