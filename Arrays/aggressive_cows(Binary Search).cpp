// Codestudio
// https://www.naukri.com/code360/problems/aggressive-cows_1082559?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=SUBMISSION

bool canWePlace(vector<int> &stalls, int k, int dis){
    int cntCow = 1, last = stalls[0];
    for(int i = 1; i<stalls.size(); i++){
        if(stalls[i] - last >= dis) {
            cntCow++;
            last = stalls[i];
        }
    }
    if(cntCow >= k) return true;
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{    
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int minDistance = 0;
    int maxDistance = stalls[n-1];

    while(minDistance <= maxDistance){
        int midDist = (minDistance + maxDistance)/2;

        if(canWePlace(stalls, k, midDist)){
            minDistance = midDist+1;
        }else {
            maxDistance = midDist - 1;
        }    
    }
    return maxDistance;    
}