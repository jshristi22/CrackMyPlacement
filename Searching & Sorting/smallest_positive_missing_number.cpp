// gfg
// https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

int missingNumber(int arr[], int n) 
{ 
    int freq[n+1] ={0};
    
    for(int i = 0; i<n; i++){
        if(arr[i] > 0 && arr[i] < n )
            freq[arr[i]] += 1;
    }
    int i = 0;
    for( i = 1; i<=n; i++){
        if(freq[i] == 0) return i;
    }
    return i;
} 