
// codestudio
// https://www.naukri.com/code360/problems/allocate-books_1090540?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=SUBMISSION

int findStd(vector<int>& arr, int n, int maxPages){
    int std = 1;  int pg = 0;
    for(int i = 0; i<n; i++){
        if(pg + arr[i] <= maxPages){
            pg += arr[i];
        }else{
            std++;
            pg = arr[i];
        }
    }
    return std;
}

int findPages(vector<int>& arr, int n, int m) {
    int low = 0, high = 0;
    for(auto it: arr){
        low = max(low, it);
        high += it;
    }
    if(m > n) return -1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = (low+high)/2; // mid has number of pages
        
        int cntStd = findStd(arr, n, mid);

        if(cntStd > m) 
            low = mid+1;
        else
            high = mid-1;        
    }
    return low;
}