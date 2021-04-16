#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lld long long int

int main()
{
	vector<int > A({1, 1, 1, 2, 3, 3, 3, 4, 4, 4, 4});

	int cnt = 0;
	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		if (i < n - 1 && A[i] == A[i + 1] && A[i] == A[i + 2])
			continue;
		else {
			A[cnt] = A[i];
			cnt++;
		}
	}

	for (int x : A)
		cout << x << " ";
	cout << endl << cnt;

}