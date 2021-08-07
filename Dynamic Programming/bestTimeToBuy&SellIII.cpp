vector<vector<vector<int>>> dp;

class Solution {
public:
    
    int profit(vector<int> &prices, int i, int prev, bool buy, int k){
        if(i == prices.size() || k == 0){
           return 0;
        }
        
        if(dp[buy][prev+1][k] != -1)
            return dp[buy][prev+1][k];
        
        if(buy){
            int p1 = profit(prices,i+1,i,0,k);
            int p2 = profit(prices,i+1,prev,1,k);
            
            return dp[buy][prev+1][k] = max(p1,p2);
        }
        
        else{
            int p1 = 0, p2 = 0;
            if(prices[i] > prices[prev])
                p1 = prices[i]-prices[prev] + profit(prices,i+1,i,1,k-1);
            p2 = profit(prices,i+1,prev,0,k);
            
            return dp[buy][prev+1][k] = max(p1,p2);

        }
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        dp.clear();
        dp.resize(2,vector<vector<int>> (prices.size()+1,vector<int>(3,-1)));
        return profit(prices,0,-1,1,2);
    }
};

// or



class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (n+1,vector<int>(3,0)));

        for(int prev = n-1; prev >= 0; prev--){
            for(int k = 1; k <= 2; k++){
                for(int i = prev+1; i < n; i++){
                    dp[1][prev][k] = max(dp[1][prev][k], dp[0][i][k]);
                    dp[0][prev][k] = max(dp[0][prev][k], prices[i]-prices[prev] + dp[1][i][k-1]);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans = max(ans, dp[1][i][2]);
        }

        return ans;
    }    
};


//or


class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        vector<int> left(n+1,0), right(n+1,0);
        int minn = prices[0], maxx = prices[n-1];
        for(int i = 1; i < n; i++){
            minn = min(minn, prices[i]);
            left[i] = max(left[i-1], prices[i]-minn);
        }
        
        for(int i = n-2; i >= 0; i--){
            maxx = max(maxx, prices[i]);
            right[i] = max(right[i+1], maxx-prices[i]);
        }

        for(int i = 1; i <= n; i++){
            ans = max(ans, left[i-1] + right[i]);
        }

        return ans;
    }    
};