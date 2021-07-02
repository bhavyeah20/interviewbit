void floodFill(vector<string> &mat, char ch, int i, int j, char color){
	if(i < 0 || j < 0 || i >= R || j >= C)
		return ;

	if(mat[i][j] != ch)
		return ;

	mat[i][j] = color;

	for(int k = 0; k < 4; k++)
		floodFill(mat,ch,i+dx[k],j+dy[k],color);
}