//https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?leftPanelTab=0

//TC: 4^(n*n) = 4^(x^2)
//SC: O(N*M)

#include <bits/stdc++.h> 
using namespace std; 

bool isSafe(int newx, int newy, vector<vector<bool>>&vis, vector<vector<int>>&arr, int n){
    if((newx >= 0 && newx < n) && (newy >=0 && newy < n) && 
    vis[newx][newy] != 1 && arr[newx][newy] == 1){
        return true;
    }
    return false;
}
void solve(int x, int y, vector< vector< int >> &arr, int n, vector<string>&ans, vector<vector<bool>>&vis, string path){
    //base case 
    if(x == n - 1 && y == n -1){
        ans.push_back(path);
        return;
    }
    //4 movements: D, L, R, U
    vis[x][y] = 1;
    //Down 
    if(isSafe(x+1, y, vis, arr, n)){
        solve(x+1, y, arr, n, ans, vis, path + 'D'); 
    } 
    //Left
    if(isSafe(x, y-1, vis, arr, n)){
        solve(x, y-1, arr, n, ans, vis, path + 'L'); 
    } 
    //Right
    if(isSafe(x, y+1, vis, arr, n)){
        solve(x, y+1, arr, n, ans, vis, path + 'R'); 
    } 
    //Up
    if(isSafe(x-1, y, vis, arr, n)){
        solve(x-1, y, arr, n, ans, vis, path + 'U'); 
    } 
    vis[x][y] = 0; 

}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string>ans;
    vector<vector<bool> >visited(n, vector<bool>(n, 0));
    string path = "";
    if(arr[0][0] == 0){
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

