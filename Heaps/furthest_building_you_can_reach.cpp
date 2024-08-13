// leetcode
// https://leetcode.com/problems/furthest-building-you-can-reach/description/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i<n-1; i++){                                                   
            int climb = heights[i+1] - heights[i];

            // considering we climb to this building using ladder;
            if(climb > 0){
                pq.push(climb);
            }            
            
            if(pq.size() > ladders){
                int smallestClimb = pq.top();
                pq.pop();

                // using bricks to cover the smallest distance
                bricks -= smallestClimb;

                if(bricks < 0){
                    return i;
                }
            }
        }
        return n -1;        
    }
};