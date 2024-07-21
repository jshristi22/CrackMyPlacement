
#include <bits/stdc++.h> 
// studies from gfg
// https://www.geeksforgeeks.org/find-the-duplicate-characters-in-a-string-in-o1-space/

using namespace std;

string findDuplicateChars(string str)
{
	// sort the string in lexicographical order
	sort(str.begin(), str.end());
	string result = "";
	for (int i = 1; i < str.length(); i++) {
		if (str[i] == str[i - 1]
			&& result.find(str[i]) == string::npos) {
			if (result.length() > 0) {
				// add a space before adding the duplicate
				// character
				result += " ";
			}
			// add the duplicate character to the result
			// string
			result += str[i];
		}
	}
	return result;
}

// Driver Code
int main()
{
	string str = "geeksforgeeks";
	string duplicates = findDuplicateChars(str);
	cout << duplicates << endl;
	return 0;
}
