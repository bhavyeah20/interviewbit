#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,long long>
#define ff first
#define ss second

const int mod = 1e9 + 7;
const int nax = 1e5 + 1;
vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
	vector<int> res;
	vector<long long> val(nax, 1);

	for (int i = 2 ; i < nax ; i++ )
	{
		for (int j = i ; j < nax ; j += i)
		{
			val[j] *= i;
			val[j] %= mod;
		}
	}

	stack<int> fw, bw;
	int n = (int)(A.size());
	vector<int> a(n), b(n);
	for (int i = 0 ; i < n ; i++ )
	{
		a[i] = 0;
		while (!fw.empty() && A[fw.top()] <= A[i])
			fw.pop();
		if (!fw.empty()) a[i] = fw.top() + 1;
		fw.push(i);
		//cout << a[i] << " " ;
	}
	//cout << "\n";
	for (int i = n - 1 ; i >= 0 ; i-- )
	{
		b[i] = n - 1;
		while (!bw.empty() && A[bw.top()] < A[i])
			bw.pop();
		if (!bw.empty()) b[i] = bw.top() - 1;
		bw.push(i);
		//cout << b[i] << " " ;
	}
	//cout << "\n";
	vector<pii> has;

	for (int i = 0 ; i < n ; i++ ) has.push_back({val[A[i]] , (long long)((b[i] - i + 1) * (i - a[i] + 1))});
	sort(has.begin() , has.end() , greater<pii>() );

	for (int i = 1 ; i < n ; i++ ) has[i].ss += has[i - 1].ss;
	//cout << has[n-1].ss << "\n";
	for (auto i : B)
	{
		int l = 0;
		int h = n - 1;
		int cur = -1;
		while (l <= h)
		{
			int m = (l + h) >> 1;
			if (i - 1 >= has[m].ss)
			{
				cur = m;
				l = m + 1;
			}
			else
				h = m - 1;
		}
		res.push_back(has[cur + 1].ff);
	}

	return res;

}