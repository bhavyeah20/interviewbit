/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


bool find(TreeNode *A, int B){
    if(!A)
        return 0;

    if(A->val == B)
        return 1;

    return find(A->left,B) || find(A->right,B);
}

int findLCA(TreeNode *A, int B, int C, int &ans){

    if(find(A,B) && find(A,C)){
        ans = A->val;
        ans = findLCA(A->left,B,C,ans);
        ans = findLCA(A->right,B,C,ans);
    }

    return ans;
}

int Solution::lca(TreeNode* A, int B, int C) {
    int ans = -1;
    return findLCA(A,B,C,ans);

}


//or

bool path(TreeNode *A, int B, vector<int> &path1){
    if(!A)
        return 0;

    path1.push_back(A->val);
    if(A->val == B){
        return 1;
    }
    
    if(path(A->left,B,path1))
        return 1;

    if(path(A->right,B,path1))
        return 1;

    path1.pop_back();
    return 0;

}
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> path1,path2;

    bool b = path(A,B,path1);
    if(!b)
        return -1;
    bool c = path(A,C,path2);
    if(!c)
        return -1;

   
    int i;
    for(i = 0; i < min(path1.size(),path2.size()); i++){
        if(path1[i] != path2[i])
            break;
    }

    return path1[--i];
}
