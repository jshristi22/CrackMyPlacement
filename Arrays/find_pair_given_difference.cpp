#include<bits/stdc++.h>
using namespace std;
// Solved it on gfg
// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1


int findPair(int n, int x, vector<int> &arr) {
        unordered_map<int, bool> m;
    
    for (int i = 0; i < n; ++i) {
        int current = arr[i];
        
        // Check if there exists an element with absolute difference x
        if (m.find(current + x) != m.end() || m.find(current - x) != m.end()) {
            return 1;
        }
        
        // Add current element to the map
        m[current] = true;
    }
    return -1;  // No pair found with the absolute difference x
    }