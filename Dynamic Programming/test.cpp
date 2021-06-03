#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int mult(int arr[], int i, int j ) {
	if (i >= j)
		return 0;

	int ans = INT_MAX;

	for (int k = i; k < j; k++) {
		int temp =  mult(arr, i, k) + mult(arr, k + 1, j)
		            + (arr[i - 1] * arr[k] * arr[j]);

		ans = min(ans, temp);
	}

	return ans;
}

int matrixMultiplication(int N, int arr[]) {
	return mult(arr, 1, N - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[] = {40, 20, 30, 10, 30};
	cout << matrixMultiplication(5, arr);
}