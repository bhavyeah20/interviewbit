#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

// int binarySearch(vector<int> &A, int B) {
// 	int n = A.size();
// 	int start = 0;
// 	int end = n - 1;


// 	while (start <= end) {
// 		int mid = (start + end) / 2;
// 		if (A[mid] == B)
// 			return mid;

// 		if (A[mid] < B) {
// 			start = mid + 1;
// 		}

// 		else
// 			end = mid - 1;
// 	}

// 	return 0;
// }

// int lowerBound(vector<int> &A, int B) {
// 	int n = A.size();
// 	int start = 0;
// 	int end = n - 1;
// 	int res = -1;

// 	while (start <= end) {
// 		int mid = (start + end) / 2;
// 		if (A[mid] == B) {
// 			res = mid;

// 			end = mid - 1;
// 		}

// 		else if (A[mid] < B) {
// 			start = mid + 1;
// 		}

// 		else
// 			end = mid - 1;
// 	}

// 	return (res == -1 ? start : res);
// }


// int upperBound(vector<int> &A, int B) {
// 	int n = A.size();
// 	int start = 0;
// 	int end = n - 1;
// 	int res = -1;

// 	while (start <= end) {
// 		int mid = (start + end) / 2;
// 		if (A[mid] == B) {
// 			res = mid;

// 			start = mid + 1;
// 		}

// 		else if (A[mid] < B) {
// 			start = mid + 1;
// 		}

// 		else
// 			end = mid - 1;
// 	}

// 	return (res == -1 ? start : res + 1);
// }

// int Solution::findMedian(vector<vector<int> > &A) {
// 	int m = A.size();
// 	int n = A[0].size();

// 	int minn = INT_MAX, maxx = INT_MIN;
// 	int targetCnt = (m * n + 1) / 2; //median is >= these many elements

// 	for (int i = 0; i < m; i++) {
// 		minn = min(A[i][0], minn);
// 	}

// 	for (int i = 0; i < m; i++) {
// 		maxx = max(A[i][n - 1], maxx);
// 	}


// 	while (minn < maxx) {
// 		int mid = maxx - (maxx - minn) / 2;
// 		int cnt = 0;
// 		for (int i = 0; i < m; i++) {
// 			cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
// 		}

// 		if (cnt < targetCnt) {
// 			minn = mid + 1;
// 		}

// 		else
// 			maxx = mid;
// 	}

// 	return minn;

// }


int books(vector<int> &A, int B) {
	int n = A.size();
	sort(A.begin(), A.end());
	int start = A[n - 1];
	int end = 0;
	for (int x : A)
		end += x;

	int minPages = INT_MAX;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		int curr = 0, cnt = 0;
		cout << "mid " << mid << endl;
		for (int i = 0; i < n; i++) {
			curr += A[i];
			if (curr > mid) {
				cnt++, curr = 0;
				i--;
			}
		}

		if (curr <= mid)
			cnt++;
		cout << "cnt " << cnt << endl;
		if (cnt == B)
			minPages = mid, end = mid - 1;

		else if (cnt > B) {
			start = mid + 1;
		}

		else
			minPages = min(minPages, mid), end = mid - 1;

		cout << "min pages " << minPages << endl;
	}

	return minPages;
}


int main()
{
	vector<int> v({73, 58, 30, 72, 44, 78, 23, 9});

	// cout << binarySearch(v, 61) << endl;
	// cout << binary_search(v.begin(), v.end(), 61) << endl;
	// cout << lowerBound(v, 61) << endl;
	// cout << lower_bound(v.begin(), v.end(), 61) - v.begin() << endl;
	// cout << upperBound(v, 5) << endl;
	// cout << upper_bound(v.begin(), v.end(), 5) - v.begin();
	cout << books(v, 5);

}




