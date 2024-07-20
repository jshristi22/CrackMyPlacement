#include <bits/stdc++.h> 

using std namespace;

// Solved on GFG
// https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1


long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
        long long mini = 1e8;
        int j = 0;
        for(int i = 0; i<n;  i++){
            j = i+m-1;
            if(j >= n) break;
            mini = min(mini, (a[j] - a[i] ));
        }
    return mini;
}