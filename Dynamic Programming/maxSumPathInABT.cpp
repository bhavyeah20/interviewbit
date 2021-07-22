
pair<int,int> maxSum(TreeNode *root){
    if(!root)
        return {-1000000000,-1000000000};

    auto left = maxSum(root->left);
    auto right = maxSum(root->right);

    pair<int,int> curr;

    curr.second = max({ root->val, left.second + root->val, 
                    right.second + root->val });
    curr.first = max({ left.first, right.first, curr.second,  left.second + root->val + right.second, });

    return curr;

}


    
int Solution::maxPathSum(TreeNode* A) {
    return maxSum(A).first;

}
