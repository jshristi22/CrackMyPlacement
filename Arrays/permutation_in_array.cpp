
#include<bits/stdc++.h>
// solved on gfg
// https://www.geeksforgeeks.org/problems/permutations-in-array1747/1


bool isPossible(long long a[], long long b[], int n, long long k) {
    int mark[n] = {0};
    // for(int i = 0; i<n;i++){
    //     for(int j = 0; j<n; j++){
    //       if(a[i] + b[j] >= k){
    //           mark[i] += 1;
    //       }
    //   } 
    // }
    
    // for(int i = 0; i<n;i++){
    //     if(mark[i] == 0) return false;
    // }
    // return true;
    
    sort(a, a + n);

    sort(b, b + n, greater<int>());

    for (int i = 0; i < n; i++){
        if (a[i] + b[i] < k){
            return false;
        }
    }
    return true;
}