

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
	int equalPartition(int N, int arr[])
	{
		return subsetSum;
	}




	int subsetSum(int &currSum, vector<int> iAns, vector<vector<int> > &ans) {


		if (currSum == k) {
			return 1;
			// ans.push(iAns);
			// return;
		}

		if (currSum > k)
			iAns.pop_back();

		for (int i = 0; i < n; i++) {
			currSum += arr[i];
			iAns.push_back(arr[i]);

			subsetSum(currSum);

			iAns.pop_back();
		}
	}

};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		int arr[N];
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		Solution ob;
		if (ob.equalPartition(N, arr))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}  // } Driver Code Ends