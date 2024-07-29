// solved on leetcode
// https://leetcode.com/problems/decode-string/

string decodeString(string s) {        
    int n = s.size();        
    string result ="";
    for(int i = 0; i<n; i++){
        if(s[i] != ']'){
            result.push_back(s[i]);
        }else {

            // pop out all chars until [ is found
            string temp ="";
            while(!result.empty() && result.back() != '['){
                temp.push_back(result.back());
                result.pop_back();
            }
            // putting string in correct order
            reverse(temp.begin(), temp.end());
            // removing starting '[' bracket
            result.pop_back();

            // look for multiple
            string num = "";
            while(!result.empty() && result.back() >= '0' && result.back() <= '9'){
                num.push_back(result.back());
                result.pop_back();
            }
            // putting number in correct order
            reverse(num.begin(), num.end());
            int n = stoi(num);

            while(n--){
                result += temp;
            }
        }   
    }
    return result;
}