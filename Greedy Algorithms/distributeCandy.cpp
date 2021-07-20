//O(n) + O(n)

int Solution::candy(vector<int> &A) {
	int n = A.size();
	vector<int> candies(n,1);

	for(int i = 1; i < n; i++){
		if(A[i] > A[i-1]){
			candies[i] = candies[i-1] + 1;
		}
	}

	for(int i = n-2; i >= 0; i--){
		if(A[i] > A[i+1]){
			candies[i] = max(candies[i], candies[i+1]+1);
		}
	}

	int sum = 0;
	for(auto it: candies)
		sum += it;

	return sum;
} 

//or

//O(n) + O(1)

class Solution {
public:
	int sum(int n){
		return (n*(n+1))/2;
	}

    int candy(vector<int>& A) {

    	if(A.size() == 1)
    		return 1;

    	int up = 0, down = 0, newSlope = 0, oldSlope = 0;
    	int candies = 0;

    	for(int i = 1; i < A.size(); i++){
    		newSlope = (A[i] > A[i-1]) ? 1 : (A[i] < A[i-1]) ? -1 : 0;

    		if((oldSlope < 0 && newSlope >= 0) || (oldSlope > 0 && newSlope == 0)){
    			candies += sum(up) + (sum(down)-1) + max(up,down)+1;
    			up = 0;
    			down = 0;
    		}

    		if(newSlope > 0)
    			up++;

    		else if(newSlope < 0)
    			down++;

    		else
    			candies++;

    		oldSlope = newSlope;
    	}

		candies += sum(up) + sum(down) + max(up,down)+1;

		return candies;        
    }
};