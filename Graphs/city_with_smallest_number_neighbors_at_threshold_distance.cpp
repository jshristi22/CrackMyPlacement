#include <bits/stdc++.h>

// City With the Smallest Number of Neighbors at a Threshold Distance
// solved on gfg
// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

 int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for(auto it: edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    
    for(int i = 0; i<n; i++) dist[i][i] = 0;
    // using floyd warshall algo
    for(int via = 0; via < n ; via ++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
        }
    }
           
    int cntMx = n;
    int city = -1;
    for(int i = 0; i<n; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if(i == j) continue;
            if(dist[i][j] <= distanceThreshold)
                cnt ++;
        }
        if( cnt <= cntMx){
            cntMx = cnt;
            city = i;
        }
    }
    return city;
}