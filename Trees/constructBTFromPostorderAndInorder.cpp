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
    TreeNode* build(int start, int end,vector<int>& postorder, vector<int>& inorder,int &idx){
        if(start > end)
            return NULL;
        int key = postorder[idx--];
        TreeNode *root = new TreeNode(key);
        
        int i;
        for(i = start; i <= end; i++){
            if(inorder[i] == key)
                break;
        }
        root->right = build(i+1,end,postorder,inorder,idx);
        root->left = build(start,i-1,postorder,inorder,idx);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;
       return build(0,postorder.size()-1,postorder,inorder,idx);
    }
};

//or

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
    
    unordered_map<int,int> mp;
    TreeNode* build(int start, int end,vector<int>& postorder, vector<int>& inorder,int &idx){
        if(start > end)
            return NULL;
        int key = postorder[idx--];
        TreeNode *root = new TreeNode(key);
        
        int i = mp[key];
        root->right = build(i+1,end,postorder,inorder,idx);
        root->left = build(start,i-1,postorder,inorder,idx);

        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    mp.clear();
        int i = 0;
        for(auto it : inorder)
            mp[it] = i++;
        int idx = postorder.size()-1;
       return build(0,postorder.size()-1,postorder,inorder,idx);
    }
};