#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define Node TreeNode
struct Node{
	int val;
	Node *left;
	Node *right;

	Node(int x){
		val =x;
		left = right = NULL;
	}
};
TreeNode *insert(TreeNode *root, int key){
	TreeNode *head = root;
    TreeNode *tail = NULL;

    if(!root){
        TreeNode *t = new TreeNode(key);
        root = t;
        return root ;
    }

    while(root){
        tail = root;

        if(root->val == key)
            return root;
    
        if(root->val < key)
            root = root->right;

        else
            root = root->left;
    }

    TreeNode *t = new TreeNode(key);
    t->left = NULL, t->right = NULL;

    if(tail->val < key)
        tail->right = t;

    else
        tail->left = t;

    return head;
}
void inorder(Node *root){
	if(root == NULL)
		return ;

	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}



int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	TreeNode *root = NULL;
	root = insert(root,10);
	root = insert(root,12);
	root = insert(root,15);
	root = insert(root,13);
	root = insert(root,11);

	inorder(root);
	cout<<endl;
}
