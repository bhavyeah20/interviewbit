#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
vector<vector<int> > prettyPrint(int A) {
    int n = A;
    n = n*2-1;
    vector<vector<int>> ans(n, vector<int> (n));

    int t = 0, b = n-1, l = 0, r = n-1;

    for(int i = A; i >= 1; i--){
        for(int j = t; j <= b; j++){
            ans[l][j] = i;
            ans[r][j] = i;
        }

        for(int j = l; j <= r; j++){
            ans[j][t] = i;
            ans[j][b] = i;
        }

        t++;
        b--;
        l++;
        r--;
    }

    return ans;
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	vector<vector<int>> ans = prettyPrint(10);
	for(auto v: ans){
		for(auto it: v)
			cout<<it<<" ";
		cout<<endl;
	}

}
