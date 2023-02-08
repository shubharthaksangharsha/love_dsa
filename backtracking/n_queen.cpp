//https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std; 

//TC: N!, SC: N*N
void addSolution(vector<vector<int>>&board, vector<vector<int>>&ans, int n){
	vector<int>temp;
	for(int i =0; i < n; i++){
		for(int j = 0; j < n; j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp); 
}
bool isSafe(int row, int col, vector<vector<int>>&board, int n){
	//we are filling from left to right
	//row same col diff 
	int x = row; 
	int y = col; 
	//check for same row 
	while(y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
	}
	x = row; 
	y = col; 
	//check for diagnal 
	while(x >= 0 && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
		x--;
	}
	//check for another diagnal
	x = row; 
	y = col;
	while(x <n  && y >= 0){
		if(board[x][y] == 1){
			return false;
		}
		y--;
		x++;
	}
	return true;
}
void solve(int col, vector<vector<int>>&ans,vector<vector<int>>&board, int n ){
	//base case 
	if (col == n){
		addSolution(board, ans, n);
		return;
	}

	//Solve 1 case and rest recursion will take care 
	for(int row = 0; row < n; row++){
		if(isSafe(row, col, board, n)){
			//if placing queen safe 
			board[row][col] = 1; 
			solve(col+1, ans, board, n);
			//backtrack 
			board[row][col] = 0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	/*Each queen should have these following properties
	a) one queen can be placed in one row only 
	b) one queen can be placed in one col only 
	c) no two queen can attack each other*/ 
	vector<vector<int> > board(n, vector<int>(n, 0));
	vector<vector<int> > ans; 
	solve(0, ans, board, n);
	return ans;
	
}