/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


    int ans;
    
    void kth(TreeNode *root, int &k, int target){
        if(!root)
            return ;
        
        kth(root->left,k,target);
        if(k == target)
            return ;
        
        k++;
        if(k == target){
            ans = root->val;
            return ;
        }
        kth(root->right,k,target);
        
        
        
    }
       

int Solution::kthsmallest(TreeNode* root, int k) {
     int curr = 0;
        kth(root,curr,k);
        return ans;
}
