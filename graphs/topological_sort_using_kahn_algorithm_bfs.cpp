#include <bits/stdc++.h> 
using namespace std; 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adj;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //get all the indegrees 
    vector<int>indegrees(v); 
    for(auto i: adj){
        for(auto j: i.second){
            indegrees[j]++;
        }
    }
    queue<int>q; 
    for(int i = 0; i < v; i++){
        if(indegrees[i] == 0){
            q.push(i);
        }
    }
    vector<int>ans; 

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto i: adj[frontNode]){
            indegrees[i]--; 
            if(indegrees[i] == 0){
                q.push(i);
            }
        }
    }
    return ans;
}