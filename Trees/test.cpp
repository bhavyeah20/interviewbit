#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int arr[100005], segmentTree[4*100005];

void buildSegmentTree(int idx, int left, int right){
	if(left == right){
		segmentTree[idx] = arr[left];
		return ;
	}

	int mid = left + (right-left)/2;
	buildSegmentTree(2*idx+1,left,mid);
	buildSegmentTree(2*idx+2,mid+1,right);

	segmentTree[idx] = max(segmentTree[2*idx+1], segmentTree[2*idx+2]); //replace with + for sum
}

int query(int idx, int left, int right, int queryLeft, int queryRight){
	if(queryLeft <= left && queryRight >= right)
		return segmentTree[idx];

	if(queryLeft > right || queryRight < left)
		return INT_MIN;

	int mid = left + (right-left)/2;
	int leftMax = query(2*idx+1, left, mid, queryLeft, queryRight);
	int rightMax = query(2*idx+2, mid+1, right, queryLeft, queryRight);

	return max(leftMax, rightMax); // replace with + for sum

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	buildSegmentTree(0,0,n-1);

	while(q--){
		int l, r;
		cin >> l >> r;

		cout<<query(0,0,n-1,l,r)<<endl;

	}

}
