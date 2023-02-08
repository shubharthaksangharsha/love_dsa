//https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0

#include <bits/stdc++.h> 
using namespace std;
//TC: 9 ^ m (no of empty cells = m), SC: O(1)(as 81 can be calls not more than that).

bool isSafe(int row, int col, vector<vector<int>>&board, int val, int n){
    for(int i = 0; i < n; i++){
        //row check
        if(board[row][i] == val){
            return false;
        }
        //col check 
        if(board[i][col] == val){
            return false;
        }
        //3x3 matrix check 
        if(board[3*(row/3) + i/3][3*(col/3) + i % 3] == val){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>>&board){
    int n = board[0].size(); 
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            //cell empty
            if (board[row][col] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isSafe(row, col, board, val, n)){
                        board[row][col] = val;
                        bool nextSolution = solve(board);
                        if(nextSolution){
                            return true;
                        } else{
                            //backtrack 
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}