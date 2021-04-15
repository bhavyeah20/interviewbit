#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lld long long int

int main()
{
	vector<int > arr1({1, 2, 4});
	vector<int > arr2({11, 22, 43});
	vector<vector<int> > arr({arr1, arr2});
	for (int x : arr.back())
		cout << x << " ";
}



