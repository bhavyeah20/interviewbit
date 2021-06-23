#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int key){
		this->val = key;
		this->left = NULL;
		this->right = NULL;
	}
};


TreeNode* insert(TreeNode *root, int key){

	if(!root){
		TreeNode *head = new TreeNode(key);
		root = head;
		return root;
	}

	if(root->val < key)
		root->right = insert(root->right, key);

	else if(root->val > key)
		root->left = insert(root->left, key);

	return root;
}

bool search(TreeNode *root, int key){
	if(!root)
		return false;

	if(root->val == key)
		return true;

	return search(root->left,key) || search(root->right, key);
}

void inorder(TreeNode *root){

	if(!root)
		return;

	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

TreeNode *inorderSuccesor(TreeNode *root){
	root = root->right;
	while(!root && root->left)
		root = root->left;

	return root;
}

TreeNode *inorderPredecessor(TreeNode *root){
	root = root->left;
	while(root && root->right)
		root = root->right;
	return root;
}

TreeNode* removed(TreeNode *root, int key){

	if(!root){
		return root;
	}

	if(root->val < key){
		root->right = removed(root->right,key);
		return root;
	}

	else if(root->val > key){
		root->left = removed(root->left, key);
		return root;

	}

	
	if(!root->left && !root->right){
		delete root;
		return NULL;
	}


	if(!root->left && root->right){
		TreeNode *t = root;
		root = root->right;
		delete t;

		return root;
	}

	if(root->left && !root->right){
		TreeNode *t = root->left;
		root = root->left;
		delete t;

		return root;
	}

	TreeNode *nextPtr = inorderSuccesor(root);
	root->val = nextPtr->val;
	root->right = removed(root->right,nextPtr->val);
	return root;

}

void morrisTraversal(TreeNode *root){

    while(root){
        if(root->left){
            TreeNode *temp = root->left;
            while(temp->right && temp->right != root){
                temp = temp->right;
            }
            if(temp->right){
                temp->right = NULL;
                root = root->right;
            }
            else{
        		cout<<root->val<<" ";
                temp->right = root;
                root = root->left;
            }
        }

        else{
        cout<<root->val<<" ";
        root = root->right;
    	}
    }
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	TreeNode *root = NULL;
	root = insert(root,50);
	root = insert(root,40);
	root = insert(root,60);
	root = insert(root,10);
	root = insert(root,45);
	root = insert(root,55);
	morrisTraversal(root);
	cout<<endl;
	// root = removed(root,434);
	// inorder(root);
	// cout<<endl;
	
}
