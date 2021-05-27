int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int maxx = 0;
    for (int i = 0; i < A.size(); i++) {
        int x = A[i], y = B[i];
        unordered_map<double, int> mp;
        for (int j = 0; j < A.size(); j++) {
            if (i == j)
                continue;

            double slope;
            if (A[j] == x)
                slope = INT_MAX;
            else
                slope = (double) B[j] - y / (double) A[j] - x;
            mp[slope]++;
            maxx = max(maxx, mp[slope]);
        }
        mp.clear();
    }

    return maxx + 1;

}



int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int maxCount = 0;
    for (int i = 0; i < A.size(); i++) {
        int maxGroupSize = 0, overlapCount = 1;
        unordered_map<double, int> slopeMap;
        for (int j = i + 1; j < A.size(); j++) {
            if ( A[i] == A[j] and B[i] == B[j] )overlapCount++; //finding overlap count
            else {
                double slope = A[i] != A[j] ? (1.0 * B[j] - B[i]) / (A[j] - A[i]) : 1e9;
                maxGroupSize = max( maxGroupSize, ++slopeMap[slope]); // simultaneously calculating the size of the biggest group sharing same slope with ( A[i], B[i] ).
            }
        }
        maxCount = max(maxCount,  overlapCount + maxGroupSize);
    }
    return maxCount;
}
