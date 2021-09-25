int diameter(Node *root, int &res){

	if(!root) return 0;

	lDia = diameter(root->left, res);
	rDia = diameter(root->right, res);

	int temp = 1 + max(lDia, rDia);
	int ans = max(temp, lDia + rDia + 1);

	res = max(res, ans);

	return temp;
}