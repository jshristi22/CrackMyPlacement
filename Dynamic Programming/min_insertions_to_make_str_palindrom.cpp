#include <bits/stdc++.h> 
// Solved on codestudio
// https://www.naukri.com/code360/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

int lps(string s, string t){
	int n = s.size();
	vector<int> prev(n + 1, 0), cur(n + 1, 0);

	for(int i = 1; i<= n; i++){
        for (int j = 1; j <= n; j++) {          
			if(s[i - 1] == t[j - 1]) 
				cur[j] = 1 + prev[j-1];
			else 
				cur[j] = max(prev[j], cur[j - 1]);
			
        }
		prev = cur;
    }
	return prev[n];
}

int minimumInsertions(string &s)
{
	/* Intution
	ex: "coding ninjas" in order to make this palindrome
	1. Keep the longest palindrome intact ("ingni")
	2. take the remaining parts reverse them and append/ prepend 
	   them to strin
	   i.  cod ingni njas "doc"
	   ii. cod "sajn" ingni njas "doc"
	   => codsajningninjasdoc which is a palindrome

	so minimum number of insertions will be string.size() - lcs(s);	
	*/
	string t = s;
	reverse(t.begin(), t.end());
	int n = s.size();
	return n - lps(s, t);
}
