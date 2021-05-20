// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


vector<int> row(101, 0);
vector<int> col(101, 0);
vector<int> diag1(2 * 101 - 1, 0), diag2(2 * 101 - 1, 0);

class Solution {
public:



	bool isValid(int x, int y, vector<vector<int> > board) {
		int n = board.size();
		if (x < 0 || x >= n || y < 0 || y >= n)
			return 0;

		if (row[x])
			return 0;

		if (col[y])
			return 0;


		if (diag1[x + y])
			return 0;

		if (diag2[x - y + n - 1])
			return 0;


		return 1;

	}

	void nextQueen(int numQueen, vector<vector<int> > &board, vector<int> iAns, vector<vector<int> > &ans) {
		int n = board.size();
		if (numQueen == n + 1) {
			ans.push_back(iAns);
			for (int i = 0; i < board.size(); i++) {
				cout << "[";
				for (int u : board[i])
					cout << u << " ";
				cout << "] " << endl;
			}
			cout << endl;
			return ;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isValid(i, j, board)) {
					board[i][j] = 1;

					row[i] = 1, col[j] = 1, diag1[i + j] = 1, diag2[i - j + n - 1] = 1;

					iAns.push_back(j + 1);
					// cout << "Placing queen number " << numQueen << "at " << i << " " << j << endl;

					nextQueen(numQueen + 1, board, iAns, ans);


					board[i][j] = 0;
					row[i] = 0, col[j] = 0, diag1[i + j] = 0, diag2[i - j + n - 1] = 0;
					iAns.pop_back();
				}
			}
		}

	}



	vector<vector<int>> nQueen(int n) {
		vector<vector<int> > board(n, vector<int> (n, 0));
		vector<int> iAns;
		vector<vector<int> > ans;
		nextQueen(1, board, iAns, ans);
		// for (int i = 0; i < board.size(); i++) {
		// 	cout << "[";
		// 	for (int u : board[i])
		// 		cout << u << " ";
		// 	cout << "] ";
		// }
		return ans;
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
				cout << "] " << endl;
			}
			cout << endl;
		}
	}
}  // } Driver Code Ends