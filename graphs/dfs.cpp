//https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std; 

void createAdjList(unordered_map<int, set<int>>&adjList, vector<vector<int>>&edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void dfs(int node, unordered_map<int, bool>&visited, unordered_map<int, set<int>>&adjList, vector<int>&component){
    component.push_back(node);
    visited[node] = 1; 

    //har connected node k liye recursive call 
    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(i, visited, adjList, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, set<int>>adjList;
    unordered_map<int, bool>visited;
    //prepare adj list 
    createAdjList(adjList, edges);

    vector<vector<int>>ans; 
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            vector<int>component;
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}