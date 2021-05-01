#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int binarySearch(vector<int> &A, int B) {
	int n = A.size();
	int start = 0;
	int end = n - 1;


	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] == B)
			return mid;

		if (A[mid] < B) {
			start = mid + 1;
		}

		else
			end = mid - 1;
	}

	return 0;
}

int lowerBound(vector<int> &A, int B) {
	int n = A.size();
	int start = 0;
	int end = n - 1;
	int res = -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] == B) {
			res = mid;

			end = mid - 1;
		}

		else if (A[mid] < B) {
			start = mid + 1;
		}

		else
			end = mid - 1;
	}

	return (res == -1 ? start : res);
}


int upperBound(vector<int> &A, int B) {
	int n = A.size();
	int start = 0;
	int end = n - 1;
	int res = -1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] == B) {
			res = mid;

			start = mid + 1;
		}

		else if (A[mid] < B) {
			start = mid + 1;
		}

		else
			end = mid - 1;
	}

	return (res == -1 ? start : res + 1);
}



int main()
{
	vector<int> v({1, 4, 11, 61, 61, 61, 100});

	cout << binarySearch(v, 61) << endl;
	cout << binary_search(v.begin(), v.end(), 61) << endl;
	cout << lowerBound(v, 61) << endl;
	cout << lower_bound(v.begin(), v.end(), 61) - v.begin() << endl;
	cout << upperBound(v, 5) << endl;
	cout << upper_bound(v.begin(), v.end(), 5) - v.begin();

}




