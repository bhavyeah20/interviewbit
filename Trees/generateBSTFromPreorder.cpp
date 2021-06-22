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
    TreeNode* bstFromPreorder(vector<int>& pre) {
    	TreeNode *p = NULL, *t = NULL;
    	int i = 0;
    	stack<TreeNode *> s;
        TreeNode *head = new TreeNode(pre[i++]);
        p = head;

        while(i  < pre.size()){
        	if(pre[i] < p->val){
        		t = new TreeNode(pre[i++]);
        		p->left = t;
        		s.push(p);
        		p = t;
        	}

        	else{
        		if(pre[i] > p->val && ( s.empty() || pre[i] < s.top()->val)){
        			t = new TreeNode(pre[i++]);
        			p->right = t;
        			p = t;
        		}

        		else{
        			p = s.top();
        			s.pop();
        		}
        	}
        }

        return head;
    }
};