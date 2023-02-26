#include<bits/stdc++.h>
using namespace std; 

class Graph{
    public: 
        unordered_map<int, list<pair<int, int>>>adj; 
        void addEdge(int u, int v, int weight){
            pair<int, int>p = make_pair(v, weight);
            adj[u].push_back(p);
        }
        void print(){
            for(auto i : adj){
                cout << i.first << " -> ";
                for(auto j: i.second){
                    cout << "(" << j.first << ", " << j.second << "), "; 
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g; 
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print();
    stack<int>s; 
    int n = 6;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }
    
}