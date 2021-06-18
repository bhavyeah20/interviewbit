/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


vector<int> ans(TreeNode *A){
    deque<TreeNode *> dq, nextDQ;
    dq.push_back(A);
    vector<int> ans;
    while(!dq.empty()){
        while(!dq.empty()){
            TreeNode *root = dq.front();
            ans.push_back(root->val);
            if(root->left){
                nextDQ.push_back(root->left);
            }
            dq.pop_front();
            if(root->right){
                dq.push_front(root->right);
            }
        }

        dq = nextDQ;
        nextDQ.clear();
    }

    return ans;
}

vector<int> Solution::solve(TreeNode* A) {
    return ans(A);
}


//or

vector<int> Solution::solve(TreeNode* a) {
    queue<TreeNode *>q;
    if(!a) return {};
    q.push(a);
    vector<int> ans;
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        while(temp)
        {
            ans.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            temp = temp->right;
        }
        
    }
    return ans;
}

//or

// map curr, right to slope
// map left to slope + 1
#define Node TreeNode
 
void build(Node *A,int i,map<int,vector<int> > &um)
{
    if(A == NULL)
    return;
  
    um[i].push_back(A->val);
   
    build(A->left,i+1,um);
    build(A->right,i,um);
}
 
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int> > um;
    vector<int> v;
    build(A,0,um);
    auto it = um.begin();
    while(it!=um.end())
    {
        vector<int> temp = it->second;
        for(int i = 0; i < temp.size(); i++)
            v.push_back(temp[i]);
        it++;
    }
    
    
    return v;
    
}