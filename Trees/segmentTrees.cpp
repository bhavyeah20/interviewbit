#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int arr[100001], segmentTree[4*100001];

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

	segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
}

void updateSegmentTree(int idx, int left, int right, int val, int arrIdx){	
	//idx -> segment tree index
	//seg[idx] holds data from [left,right] indices of arr
	// update arr[arrIdx] to val

	if(left == right){
		arr[arrIdx] = val;
		segmentTree[idx] = val;

		return ;
	}

	int mid = left + (right-left)/2;
	if(arrIdx <= mid){
		updateSegmentTree(2*idx+1,left,mid,val,arrIdx);
	}

	else{
		updateSegmentTree(2*idx+2,mid+1,right,val,arrIdx);
	}

	segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];

}

int query(int idx, int left, int right, int queryLeft, int queryRight){
	//process query from arr[queryLeft] to arr[queryRight]

	// no overlap
	if(queryLeft > right || queryRight < left){
		return 0;
	}

	// complete overlap
	if(queryLeft <= left && queryRight >= right){
		//will contribute to answer
		return segmentTree[idx];
	}

	//partial overlap
	int mid = left + (right-left)/2;
	return query(2*idx+1,left,mid,queryLeft,queryRight) + query(2*idx+2, mid+1, right, queryLeft, queryRight);
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	cout<<"Enter array size"<<endl;
	int size = 0, queries = 0;
	cin >> size;
	cout<<"Enter array elements"<<endl;
	
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}

	buildSegmentTree(0,0,size-1);

	cout<<"Enter number of queries"<<endl;
	cin >> queries;

	while(queries--){
		bool update = 0;
		int a, b;
		cin >> update >> a >> b;
		if(update){
			updateSegmentTree(0,0,size-1,a,b);
		}else{
			cout<<query(0,0,size-1,a,b)<<endl;
		}
	}




}
	