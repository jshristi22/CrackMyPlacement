
// leetcode
// https://leetcode.com/problems/4sum/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> t;        
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    // O(N^3)
    for(int i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n-1; j++){
            if(j != i+1 &&nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = nums[i] + nums[j];
                sum+= nums[k];
                sum+= nums[l];
                
                if(sum > target){
                    l--;
                }else if (sum < target){
                    k++;
                }else{
                    vector<int> t = {nums[i] , nums[j], nums[k] , nums[l]};
                    ans.push_back(t);
                    k++, l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }

            }
        }
    }
    return ans;


    // O(N^4)
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                for(int l = k+1; l<n; l++){
                    long long sum = nums[i] + nums[j];
                    sum+= nums[k];
                    sum+= nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i] , nums[j], nums[k] , nums[l]};
                        sort(temp.begin(), temp.end());
                        t.insert(temp);
                    }
                }
            }
        }
    }
    // vector<vector<int>> ans(t.begin(), t.end());
    return ans;
