bool isSur(){
vis[i][j] = 1;

if(isSur(i+1,j) && isSur(i,j-1) && isSur(i-1,j) && isSur(i,j+1))
    A[i][j] = 'X'. r
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size(), m = A[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'O'){
                if(j-1 >= 0 && A[i][j] != 'X')
                    continue;

                if(i-1 >= 0 && A[i][j] != 'X')
                    continue;

                int right = j + 1;
                while(right < m && A[i][right] != 'X')
                    right++;

                if(right == m)
                    continue;

                while(right < m && A[i][right] != 'X')
                    right++;

                if(right == m)
                    continue;
                


            }    
        }
    }
}
