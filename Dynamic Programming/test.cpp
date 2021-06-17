#include<bits/stdc++.h>

using namespace std;

int main() {

	int n ;
	cin >> n;

	vector<int> arr(n,1);
	int sum = 0;
	for(int i : arr)
	sum += i;

	cout<<"Sum is  "<<sum;
}
