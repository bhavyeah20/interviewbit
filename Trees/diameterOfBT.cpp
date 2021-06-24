diameter(){
	lDia = diameter(root->left);
	rDia = diameter(root->right);

	return max({lDia, rDia, 1 + height(left) + height(right)})
}