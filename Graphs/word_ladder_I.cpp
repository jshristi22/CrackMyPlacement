#include <bits/stdc++.h> 

using std namespace;

// Solved on gfg
// https://www.geeksforgeeks.org/problems/word-ladder/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=word-ladder



 int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    queue<pair<string, int>> q;
    q.push({startWord,1});
    set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        
        if(word == targetWord) return steps;
        
        for(int i = 0; i<word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                // it exists
                if(st.find(word) != st.end()){
                    // erase it from set 
                    st.erase(word);
                    // push to queue
                    q.push({word, steps+1});
                    
                }
            }
            word[i] = original;
        }
    }
    return 0;    
}