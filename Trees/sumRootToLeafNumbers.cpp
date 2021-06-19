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
   
   /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void build(TreeNode *A, int &runningTotal, int &total){
    if(!A)
        return ;

    if(!A->left && !A->right){
        runningTotal = runningTotal * 10 +  A->val;
        total += runningTotal;
    runningTotal = (runningTotal - A->val) / 10;
        return ;
    }

   
    runningTotal = runningTotal * 10 +  A->val;
    build(A->left,runningTotal,total);
    build(A->right,runningTotal,total);
    runningTotal = (runningTotal - A->val) / 10;
}

 int sumNumbers(TreeNode* A) {
        
    int runningTotal = 0, total = 0;
    build(A,runningTotal, total);

    return total;
}

};