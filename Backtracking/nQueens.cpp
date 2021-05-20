// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class Solution {
public:

	bool isValid(int x, int y, vector<vector<int> > board) {
		int n = boad.size();
		if (x < 0 || x >= n || y < 0 || y >= n)
			return 0;

		for (int i = 0; i < n; i++) {
			if (board[x][i])
				return 0;
		}

		for (int i = 0; i < n; i++) {
			if (board[i][y])
				return 0;
		}


		for (int i = x, j = y; i >= 0, j < n; i--, j++) {
			if (board[i][j])
				return 0;
		}

		for (int i = x, j = y; i < n, j >= 0; i++, j--) {
			if (board[i][j])
				return 0;
		}


		return 1;

	}

	bool nextQueen(int numQueen, vector<vector<int> > &board) {
		if (numQueen == n + 1)
			return 1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isValid(i, j, board)) {
					board[i][j] = 1;

					if (nextQueen(numQueen + 1, board))
						return 1;

					board[i][j] = 0;
				}
			}
		}

		return 0;
	}



	vector<vector<int>> nQueen(int n) {
		vector<vector<int> > board(n, vector<int> (n, 0));

		int flag = nextQueen(1, board);
		return board;
	}
};



// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		Solution ob;
		vector<vector<int>> ans = ob.nQueen(n);
		if (ans.size() == 0)
			cout << -1 << "\n";
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << "[";
				for (int u : ans[i])
					cout << u << " ";
				cout << "] ";
			}
			cout << endl;
		}
	}
	return 0;
}  // } Driver Code Ends