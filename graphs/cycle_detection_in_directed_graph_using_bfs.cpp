#include<bits/stdc++.h>
using namespace std; 

bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	//using Kahns Algorithm 
	unordered_map<int, list<int>>adj; 
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}
	vector<int>indegree(v);
	for(auto i: adj){
		for(auto j: i.second){
			indegree[j]++;
		}
	}
	queue<int>q; 
	int count = 0;
	for(int i = 0; i < v; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	while (!q.empty()){
		int frontNode = q.front();
		q.pop();
		count++;
		for(auto i: adj[frontNode]){
			indegree[i]--;
			if (indegree[i] == 0){
				q.push(i);
			}
		}
	}
	if (count == v){
		return false; 
	}
	return true;

}
