// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];

        // making graph
        for(int i = 0; i<n; i++){
            // check for U parent
            if(i == headID) continue;
            adj[manager[i]].push_back(i);
        }
        // 0, 1
        queue<pair<int, int>> q;
        q.push({headID, 0});
        int maxTime = 0;
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            int node = it.first;
            int t = it.second;

            maxTime = max(maxTime , t);
            for(auto it: adj[node]){
                q.push({it, t + informTime[node]});
            }
        }

        return maxTime;
    }
};