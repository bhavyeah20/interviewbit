int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
  int curr = 0, sum = INT_MIN;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      // left = i,j;

      for (int k = i; k < R; k++) {
        for (int l = j; l < C; l++) {
          //right = k,l

          for (int ii = i; ii <= k; ii++) {
            for (int jj = j; jj <= l; jj++) {
              curr += M[ii][jj];
            }
          }

          sum = max(curr, sum);
          curr = 0;
        }
      }
    }
  }

  return sum;
}

//or

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
  vector<int> sum(R, 0);
  int maxSum = INT_MIN;
  for (int left = 0; left < C ; left++) {
    fill_n(sum.begin(), R, 0);
    for (int right = left; right < C; right++) {
      //Removed liability of Top and Bottom n^4 -> n^2

      //Store sum of each col from L to R in a sum array
      for (int row = 0; row < R; row++) {
        sum[row] += M[row][right];
      }

      //Apply kadanes on this row sum vertically
      //sum n^2 -> n
      int currSum = 0;
      for (int i = 0; i < R; i++) {
        currSum += sum[i];
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
          currSum = 0;
        }
      }
    }
  }

  return  maxSum;
}