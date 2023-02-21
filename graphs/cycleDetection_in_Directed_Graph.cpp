//https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_920545?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std; 

bool checkCycleDFS(int node, unordered_map<int, bool>&visited, unordered_map<int, bool>&dfsVisited, unordered_map<int, list<int>>&adj ){
	visited[node] = true; 
	dfsVisited[node] = true; 
	for(auto neighbour: adj[node]){
		if(!visited[neighbour]){
			bool cycleDetected = checkCycleDFS(neighbour, visited, dfsVisited, adj);
			if (cycleDetected){
				return true;
			}
		} else if(dfsVisited[neighbour]){
			//visited true
			return true;
		}
	}
	dfsVisited[node] = false; 
	return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	unordered_map<int, list<int>>adj;
	//create adj list 
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}

	unordered_map<int, bool>visited;
	unordered_map<int, bool>dfsVisited;  
	for(int i = 0; i < v; i++){
		if (!visited[i]){
			bool ans = checkCycleDFS(i, visited, dfsVisited, adj);
			if (ans){
				return true;
			}
		}
	}
	return false;
}
