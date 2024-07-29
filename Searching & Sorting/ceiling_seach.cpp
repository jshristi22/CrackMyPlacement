#include <bits/stdc++.h>
using namespace std;

// using binary search 
// TC: O(log N)
int ceilSearch(int arr[], int low, int high, int target)
{	
	int midEle = (low + high) / 2; 

	if (target <= arr[low])
		return low;

	if (target > arr[high])
		return -1;

	if (arr[midEle] == target)
		return midEle;

	else if (arr[midEle] < target) {
		if (midEle + 1 <= high && target <= arr[midEle + 1])
			return midEle + 1;
		else
			return ceilSearch(arr, midEle + 1, high, target);
	}

	else {
		if (midEle - 1 >= low && target > arr[midEle - 1])
			return midEle;
		else
			return ceilSearch(arr, low, midEle - 1, target);
	}
}

