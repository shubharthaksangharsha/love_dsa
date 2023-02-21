//https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int src, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&adj){
    unordered_map<int, int> parent;
    queue<int>q; 
    parent[src] = -1; 
    visited[src] = 1; 
    q.push(src);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour: adj[frontNode]){
            //cycle detection condition
            if(visited[neighbour] && neighbour != parent[frontNode]){
                return true;
            } else if(!visited[neighbour]){
                q.push(neighbour); 
                visited[neighbour] = 1; 
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node, int parent, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&adj ){
    visited[node] = true; 
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour, node, visited, adj);
            if(cycleDetected){
                return true;
            }
        } else if(neighbour != parent) {
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>>adj; 
    //create adjacency list  
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool>visited;
    //to handle disconnected componenets 
    for(int i = 0; i < n ; i++){
        if(!visited[i]){
            // bool ans = isCyclicBFS(i, visited, adj);
            bool ans = isCyclicDFS(i, -1, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
