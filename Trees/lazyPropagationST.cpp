#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int arr[100001], segmentTree[4*100001], lazyTree[4*100001];

void buildSegmentTree(int idx, int left, int right){
	//idx -> segment tree index
	//seg[idx] holds data from [left,right] indices of arr
	if(left == right){
		segmentTree[idx] = arr[left];
		return ;
	}

	int mid = left + (right-left)/2;
	buildSegmentTree(2*idx+1,left,mid);
	buildSegmentTree(2*idx+2,mid+1,right);

	segmentTree[idx] = min(segmentTree[2*idx+1],segmentTree[2*idx+2]);
}

void updateLazySegmentTree(int idx, int left, int right, int inc, int queryLeft, int queryRight){	
	//idx -> segment tree index
	//seg[idx] holds data from [left,right] indices of arr
	// update arr[queryLeft, queryRight] to += inc

	if(lazyTree[idx]){
		segmentTree[idx] += lazyTree[idx];

		if(left != right){
			lazyTree[2*idx+1] += lazyTree[idx];
			lazyTree[2*idx+2] += lazyTree[idx];
		}
		lazyTree[idx] = 0;
	}

	if(queryLeft > right || queryRight < left){
		return ;
	}

	if(queryLeft <= left && queryRight >= right){
		segmentTree[idx] += inc;
		if(left != right){
			lazyTree[2*idx+1] += inc;
			lazyTree[2*idx+2] += inc;
		}

		return ;
	}

	int mid = left + (right-left)/2;
	updateLazySegmentTree(2*idx+1,left,mid,inc,queryLeft,queryRight);
	updateLazySegmentTree(2*idx+2,mid+1,right,inc,queryLeft,queryRight);

	segmentTree[idx] = min(segmentTree[2*idx+1], segmentTree[2*idx+2]);


}
	

int query(int idx, int left, int right, int queryLeft, int queryRight){
	//process query from arr[queryLeft] to arr[queryRight]


	if(lazyTree[idx]){
		segmentTree[idx] += lazyTree[idx];

		if(left != right){
			lazyTree[2*idx+1] += lazyTree[idx];
			lazyTree[2*idx+2] += lazyTree[idx];
		}
		lazyTree[idx] = 0;
	}

	// no overlap

	if(queryLeft > right || queryRight < left){
		return INT_MAX;
	}

	// complete overlap
	if(queryLeft <= left && queryRight >= right){
		//will contribute to answer
		return segmentTree[idx];
	}

	//partial overlap
	int mid = left + (right-left)/2;
	return min(query(2*idx+1,left,mid,queryLeft,queryRight),query(2*idx+2, mid+1, right, queryLeft, queryRight));
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	arr[0] = 1;
	arr[1] = 3;
	arr[2] = -2;
	arr[3] = 4;

	buildSegmentTree(0,0,3);
	updateLazySegmentTree(0,0,3,3,0,3);
	updateLazySegmentTree(0,0,3,2,0,1);

	for(int i = 0; i <= 6; i++){
		cout<<segmentTree[i]<<endl;
	}


	for(int i = 0; i <= 6; i++){
		cout<<lazyTree[i]<<endl;
	}

	cout<<query(0,0,3,1,2)<<endl;

	for(int i = 0; i <= 6; i++){
		cout<<segmentTree[i]<<endl;
	}


	for(int i = 0; i <= 6; i++){
		cout<<lazyTree[i]<<endl;
	}
}
	