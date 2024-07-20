#include <bits/stdc++.h> 

using std namespace;

// Solved on gfg
// https://www.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	int indegree[N] = {0};
	vector<int> adj[N];
	
	for(auto it: prerequisites){
		adj[it.first].push_back(it.second);
	}
	
	for(int i = 0; i<N; i++){
		for(auto it: adj[i]){
			indegree[it]++;
		}
		
	}
	queue<int> q;
	for(int i = 0; i<N; i++){
		if(indegree[i] == 0) q.push(i);
	}
	
	int cnt = 0;
	while(!q.empty()){
		int node = q.front();
		cnt++;
		q.pop();
		// visiting neighbors
		for(auto it: adj[node]){
			indegree[it]--;
			if(indegree[it] == 0) {
				q.push(it);
			}
		}
	}
	
	return cnt == N;
}