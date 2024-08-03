
// leetcode
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int high = n-1;
        int low = 0;

        while(low<= high){
            int mid = (low+high) / 2;
            if(arr[mid] == k) return mid;


            // check which part is sorted
            if(arr[low] <= arr[mid]){
                // left is sorted
                if(arr[low] <= k && k <= arr[mid])
                    high = mid-1;                
                else low = mid+1;                
            }else{
                // right is sorted
                if(arr[mid] <= k && k <=arr[high])
                    low = mid + 1;
                else high = mid - 1;
            }
        }    
        return -1;
    }
};