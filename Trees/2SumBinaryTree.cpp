/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 2 pointer tech in sorted array

stack<TreeNode *> minStack, maxStack;

void pushMin(TreeNode *A){
    while(A){
        minStack.push(A);
        A = A->left;
    }
}

void pushMax(TreeNode *A){
    while(A){
        maxStack.push(A);
        A = A->right;
    }
}

TreeNode *currMin(){
    return minStack.top();
}

TreeNode *currMax(){
    return maxStack.top();
}

void nextMin(){
    TreeNode *root = minStack.top();
    minStack.pop();
    pushMin(root->right);
}

void nextMax(){
    TreeNode *root = maxStack.top();
    maxStack.pop();
    pushMax(root->left);
}

int Solution::t2Sum(TreeNode* A, int B) {
    while(!minStack.empty()){
        minStack.pop();
    }

    while(!maxStack.empty()){
        maxStack.pop();
    }
    TreeNode *r1 = A, *r2 = A;
    pushMin(r1);
    pushMax(r2);

    while(!minStack.empty() && !maxStack.empty()){
        if(currMin()->val + currMax()->val == B && currMin() != currMax())
            return 1;

        if(currMin()->val + currMax()->val > B){
            nextMax();
        }

        else
            nextMin();
    }
    return 0;
}



