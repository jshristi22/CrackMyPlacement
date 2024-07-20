#include <bits/stdc++.h> 

using std namespace;

// Solved on Codestudio
// https://www.naukri.com/code360/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM


bool f(int idx, int target,  vector<int> &arr, vector<vector<int>> &dp){
	if(target == 0 ) return true;
	if(idx == 0) return arr[idx] == target;

	if(dp[idx][target] != -1) return dp[idx][target];

	bool pick = false;
	if(target > arr[idx]) pick = f(idx -1, target - arr[idx], arr, dp);

	bool notPick = f(idx - 1, target, arr, dp);

	return dp[idx][target] = pick || notPick;
}


bool canPartition(vector<int> &arr, int n)
{
	int sum = 0;
	for(auto it: arr) 
		sum += it;
	if(sum % 2) 
		return false;
	
	int target = sum/2;
	vector<vector<int>> dp(n, vector<int> (target + 1, -1));

	return f(n-1, target, arr, dp);
}
