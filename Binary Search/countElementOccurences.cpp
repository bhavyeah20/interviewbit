int Solution::findCount(const vector<int> &A, int B) {
    int n = A.size();
    int start = 0;
    int end = n - 1;
    int res = -1;
    int cnt = 0;


    int lb = -1, ub = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == B) {
            lb = mid;
            end = mid - 1;
        }

        else if (A[mid] < B) {
            start = mid + 1;
        }

        else
            end = mid - 1;
    }

    if (lb == -1)
        return 0;

    start = 0;
    end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A[mid] == B) {
            ub = mid;
            start = mid + 1;
        }

        else if (A[mid] < B) {
            start = mid + 1;
        }

        else
            end = mid - 1;
    }

    return ub - lb + 1;
}