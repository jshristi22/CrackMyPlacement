
#include <bits/stdc++.h> 
using namespace std; 

// gfg
// TC: O(N)

bool sortArr(int a[], int n) 
{ 
    int start = -1; 
    int end = -1; 
  
    //   find the unsorted part of the array, store it's starting and ending indexs
    for (int i = 0; i < n - 1; i++) { 
        if (a[i] > a[i + 1]) { 
            if (start == -1) { 
                start = i; //starting index
            } 
            end = i + 1; //ending index
        } 
    } 
  
    if (x != -1) { 
        reverse(a + start, a + end + 1); //reverse the unsorted part
        for (int i = 0; i < n - 1; i++) { 
            if (a[i] > a[i + 1]) {  //check if the array is now sorted or not
                return false; //if not return false                
            } 
        } 
    } 
    return true; // if yes return true;
} 
