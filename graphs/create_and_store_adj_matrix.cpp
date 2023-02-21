//https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=1

#include<bits/stdc++.h>
using namespace std;

vector< vector<int>> printAdjacency(int n, int m, vector< vector<int>>&edges){
    vector<int>ans[n];
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
        
    }

    vector<vector<int> >adj(n); 
    for(int i = 0; i < n; i++){
        adj[i].push_back(i);

        //entering neighbour 
        for(int j  = 0; j < ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
        
    }
    return adj;
}
int main(){
  
    return 0;
}