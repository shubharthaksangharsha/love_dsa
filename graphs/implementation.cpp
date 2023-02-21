//Author: Shubharthak Sangharasha
/*  Date: 2023-02-20 10:02:40
         Description: Implementation of graph 
*/
#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class graph{
    public:
        unordered_map<T, list<int>> adj; 
        unordered_map<T, bool>visited;
        vector<T>bfs_ans;
        vector<T>dfs_ans;
        int vertex; 
        void addEdge(T u, T v, bool direction){
            //direction -> 0 -> undirected 
            //direction -> 1 -> directed 

            //create edge from u to v 
            adj[u].push_back(v);
            if(!direction){
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i: adj){
                cout << i.first << "->"; 
                for(auto j: i.second){
                    cout << j <<", ";
                }
                cout << endl;
            }
        }
        void bfs_helper(T node){
            queue<T>q; 
            q.push(node);
            this->visited[node] = 1;
            while(!q.empty()){
                T frontNode = q.front();
                q.pop();
                cout << frontNode << ", ";
                bfs_ans.push_back(frontNode);

                for(auto i: this->adj[frontNode]){
                    if (!this->visited[i]){
                        q.push(i);
                        this->visited[i] = 1;
                    }
                }
            }
        }
        void bfs(){
            this->visited.clear();
            cout << "Enter the total number of vertices: ";
            cin >> vertex;
            for(int i = 0; i < v; i++){
                if (!visited[i]){
                    bfs_helper(i, this->adj, this->visited, this->ans);
                }
            }
        }
        void dfs_helper(T node){
            this -> visited[node] = 1; 
            cout << node << ", ";
            dfs_ans.push_back(node);
            for(auto i: this->adj[node]){
                dfs_helper(i);
            }
        }
        void dfs(){
            visited.clear(); 
            for(int i = 0; i < this -> vertex; i++){
                if(visited[i]){
                    dfs_helper(i);
                }
            }
        }
};




int main(){
    int n, m; 
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m; 
    graph<int> g; 
    for(int i = 0; i < m; i++){
        int u, v; 
        cin >> u >> v; 
        g.addEdge(u, v, 0);
    }
    //printing graph 
    g.printAdjList();

    //BFS 
    g.bfs();
    return 0;
}