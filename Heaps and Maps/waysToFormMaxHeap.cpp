#define ll long long int

ll mod = 1e9+7;

vector<vector<long long>> dp(101, vector<long long> (101,-1));
vector<long long> heap(101,-1);
 
long long nCr(long long n, long long r){
    if(r > n){
        return 0;
    }
 
    if(r == 0 || n <= 1)
        return 1;
 
    if(dp[n][r] != -1)
        return dp[n][r];
 
 
    dp[n][r] = ((nCr(n-1,r) % mod) + (nCr(n-1,r-1) % mod)) % mod;
 
 
    return dp[n][r];
}
 
long long power(long long n, long long h){
    long long res = 1;
    while(h){
        if(h & 1){
            res = ((res % mod) * (n % mod)) % mod;
        }
 
        n = ((n % mod) * (n % mod)) % mod;
        h >>= 1;
    }
 
    return res % mod;
}
 
long long ways(int N){
    if(N <= 1){
        return 1;
    }
 
    if(heap[N] != -1){
        return heap[N];
    }
 
    long long H = log2(N);
    long long l = power(2,H-1) - 1;
    l += min(power(2,H-1), N+1-power(2,H));
 
    long long r = N-l-1;
 
    heap[N] =  1LL * (nCr(N-1,l) % mod);
    heap[N] = heap[N] % mod * (ways(l) % mod);
    heap[N] = heap[N] % mod * (ways(r) % mod);
    heap[N] %= mod;
    return heap[N] % mod; 
}
 
int Solution::solve(int A) {
 	long long x = ways(A) % mod;
    return x;
}