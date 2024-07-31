// leetcode
// https://leetcode.com/problems/trapping-rain-water/
int trap(vector<int>& height) {
    long long ans = 0;
    int n = height.size();
    int s = 0, e = n-1;
    int l = 0, r=0;
    while(s<e){
        l = max(l, height[s]);
        r = max(r, height[e]);
        if(l<r) ans += l - height[s++];
        else ans += r - height[e--];
    }
    
    return ans;
    }            