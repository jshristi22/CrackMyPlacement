
#include<bits/stdc++.h>
using namespace std;
// Solved it on GFG
// https://www.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary


 public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        // making graph
        for(int i = 0; i<N-1; i++){
            string str1 = dict[i];
            string str2 = dict[i+1];
            int len = min(str1.size(), str2.size());
            for(int pt = 0; pt < len; pt++){
                if(str1[pt] != str2[pt]){
                    adj[str1[pt] - 'a'].push_back(str2[pt] - 'a');
                    break;
                }
            }
        }
        
        // calculating indegrees
        int indegree[K] = {0};
        for(int i = 0; i<K; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        // storing 0 indegree nodes in queue;
        queue<int> q;
        
        for(int i = 0; i<K; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> topo;
        // finding the order
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            // visiting neighbor nodes
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        string ans = "";
        for(auto it: topo){
            ans += char(it + 'a');
        }
        return ans;
    }