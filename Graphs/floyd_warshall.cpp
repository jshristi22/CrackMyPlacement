
#include<bits/stdc++.h>
using namespace std;
// Solved it on gfg
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Using floyd warshal algo;
/*
It's a brute force approach where you visit all nodes from every node.
    ~ it can detect a negative cycle
    ~ it works on directed graphs.
    ~ to make it work for undirected graphs, 
      add two edges with same weight by altering the src & dest node
*/
void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
            if(i == j) matrix[i][j] = 0;
        }
    }
    
    for(int via = 0; via<n; via ++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                matrix[i][j] = min(matrix[i][j] ,matrix[i][via] + matrix[via][j]);
            }
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
        }
    }
    
}