int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int maxx = 0;
    map<pair<long long, long long>, int> mp; // slope -> cnt;

    for (int i = 0; i < A.size(); i++) {
        int x = A[i], y = B[i];
        int same = 1;
        int curr = 0;
        for (int j = i + 1; j < A.size(); j++) {

            long long first = B[j] - y;
            long long second = A[j] - x;

            if (!first && !second) {
                same++;
                continue;

            }

            if (!second) {
                if (first > 0)
                    first = INT_MAX;
                else
                    first = INT_MIN;
            }
            else {
                bool sign = first < 0 ^ second < 0;
                first = labs(first), second = labs(second);
                if (sign)
                    first *= -1;
            }

            long long gcd = __gcd(first, second);
            first = gcd ? first / gcd : first;
            second = gcd ? second / gcd : second;
            mp[make_pair(first, second)]++;
            curr = max(curr, mp[make_pair(first, second)]);
        }
        curr += same;
        maxx = max(maxx, curr);
        mp.clear();
    }

    if (A.empty())
        return 0;
    return maxx;
}

// not precise

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
                slope = (double) (B[j] - y) / (double) (A[j] - x);

            mp[slope]++;
            maxx = max(maxx, mp[slope]);
        }
        mp.clear();
    }
    if (A.empty())
        return 0;
    return maxx + 1;

}
