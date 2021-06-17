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
class Solution {
public:
    TreeNode* build(int start, int end,vector<int>& preorder, vector<int>& inorder,int &idx){
        if(start > end)
            return NULL;
        int key = preorder[idx++];
        TreeNode *root = new TreeNode(key);
        
        int i;
        for(i = start; i <= end; i++){
            if(inorder[i] == key)
                break;
        }

        root->left = build(start,i-1,preorder,inorder,idx);
        root->right = build(i+1,end,preorder,inorder,idx);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
       return build(0,preorder.size()-1,preorder,inorder,idx);
    }
};