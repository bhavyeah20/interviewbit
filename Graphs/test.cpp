#include<bits/stdc++.h>

using namespace std;

    //mergesort O(nlogn)
    vector<int> sortt(int start, int end, vector<int> &A){
        
        if(start >= end)
            return A;
        
        int mid = start + (end - start) / 2;
        
        vector<int> left;
        vector<int> right;
        
        for(int i = 0; i < mid; i++){
            left.push_back(A[i]);
            right.push_back(A[A.size()-i-1]);
        }
        
        left.push_back(A[mid]);
        
        left = sortt(start,mid,left);
        right = sortt(mid+1,end,right);
        
        for(int i = 0, j = 0, k = 0; i < left.size() || j < right.size();){
            
            int l = 1e9, r = 1e9;
            
            if(i < left.size())
                l = left[i];
            
            if(j < right.size())
                r = right[j];
            
            if(l <= r){
                A[k] = left[i];
                i++;                
            }
            
            else {
                A[k] = right[j];
                j++;
            }
            k++;
        }
        
        left.clear();
        right.clear();
        return A;
    }
        
     
    
    vector<int> sortArray(vector<int>& A) {
        //worst case O(nlogn) always better than qs O(n^2) 
        int i = 0;
        for(i = 0; i < A.size() - 1; i++){
            if(A[i] > A[i+1])
                break;
        }
        
        if(i == A.size() - 1) return A;
        
        A = sortt(0,A.size()-1,A);
        
        return A;
    }
int main(){
    vector<int> v({5,1,1,2,0,3});
    v = sortArray(v);
    for(auto it: v) cout<<it<<" ";
}