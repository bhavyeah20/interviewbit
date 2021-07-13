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

void heapifyUtil(int i, int heapSize, int *heapArray){
	int j = 2 * i;
	while(j <= heapSize){
		if(j+1 <= heapSize && heapArray[j+1] > heapArray[j])
			j++;

		if(heapArray[i] < heapArray[j]){
			swap(heapArray[i],heapArray[j]);
			i = j;
			j = 2 * i;
		}

		else
			break;
	}
}

void heapify(int heapSize, int *heapArray){
	int i = heapSize/2;

	for(i; i >= 1; i--){
		heapifyUtil(i,heapSize,heapArray);
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
		heapArray[++heapSize] = it;
	}


	heapify(heapSize,heapArray);

	show(heapArray,heapSize);

	for(int i = heapSize; i >= 1; i--){
		swap(heapArray[1], heapArray[i]);

		heapifyUtil(1,i-1,heapArray);
	}

	show(heapArray,heapSize);

}