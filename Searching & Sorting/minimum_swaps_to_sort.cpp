

// GFG
// https://www.geeksforgeeks.org/problems/minimum-swaps/1

int minSwaps(vector<int>&nums)
{
    int n = nums.size();
    pair<int, int> arr[n];
    
    for(int i = 0; i < n; i++){
        arr[i].first = nums[i];
        arr[i].second = i;
    }
    
    sort(arr, arr + n);
    vector<bool> vis(n, false);
    int ans = 0;
    
    for(int i = 0; i<n; i++){
        if(vis[i] || arr[i].second == i) continue;
        
        int amt = 0;
        int j = i;
        while(!vis[j]){
            vis[j] = 1;
            
            j = arr[j].second;
            amt++;
        }
        
        if(amt > 0){
            ans += amt - 1;
        }
    }
    return ans;
}