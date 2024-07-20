
#include <bits/stdc++.h> 

using std namespace;

// Solved on leetcode
// https://leetcode.com/problems/set-matrix-zeroes/description/

void setZeroes(vector<vector<int>>& matrix) {
    bool flag = false;
    vector<int> rows, cols;  
    for(int r = 0; r<matrix.size() && !flag; r++){
        for(int c = 0; c<matrix[0].size() && !flag; c++){
            if(matrix[r][c] == 0){
                rows.push_back(r);
                cols.push_back(c) ;                   
            }
        }
    }
        while(cols.size() > 0){
        int c = cols.back();
        for(int i = 0; i<matrix.size(); i++){
            matrix[i][c] = 0;
        }
        cols.pop_back();
    }       

    while(rows.size() > 0){
        int r = rows.back();
        for(int i = 0; i<matrix[0].size();  i++){
            matrix[r][i] = 0;
        }
        rows.pop_back();
    }
    flag = true;
}

