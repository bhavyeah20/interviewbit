#include<bits/stdc++.h>

using namespace std;
	
#define endl "\n"

int MAX_SIZE = 1e5;

void show(int *heapArray, int n){
	for(int i = 1; i <= n; i++){
		cout<<heapArray[i]<<" ";
	}

	cout<<endl;
}

void insert(int it, int &heapSize,int *heapArray){
	heapSize++;
	heapArray[heapSize] = it;
	int i = heapSize;
	while(i > 1 && heapArray[i] > heapArray[i/2]){
		swap(heapArray[i], heapArray[i/2]);
		i /= 2;
	}
}

void Delete(int &heapSize, int *A){
	int i,j;
	swap(A[1],A[heapSize]);
	heapSize--;

	i = 1, j = 2*i;
	while(j <= heapSize){
		if(j+1 <= heapSize && A[j+1] > A[j])
			j++;

		if(A[i] < A[j]){
			swap(A[i],A[j]);
			i = j;
			j = 2 * i;
		}

		else{
			break;
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int heapArray[MAX_SIZE];

	int size;
	int heapSize = 0;
	cin >> size;

	for(int i = 1; i <= size; i++){
		int it;
		cin >> it;
		insert(it,heapSize,heapArray);
	}

	show(heapArray,heapSize);

	int sz = heapSize;
	while(heapSize){
		Delete(heapSize, heapArray);	
	}

	show(heapArray,sz);

}