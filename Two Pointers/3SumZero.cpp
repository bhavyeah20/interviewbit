vector<vector<int> > Solution::threeSum(vector<int> &A) {

	int n = A.size();
	sort(A.begin(), A.end());

	vector<vector<int> > ans;

	for (int j = 0; j < n; j++)
	{

		if (j > 0 && A[j] == A[j - 1])
			continue;

		int i = j + 1, k = n - 1;

		int target = -1 * A[j];
		while (i < k)
		{
			if (A[i] + A[k] == target)
			{

				vector<int> temp({A[i], A[j], A[k]});

				ans.push_back(temp);

				temp.clear();

				i++;
			}
			else if (A[i] + A[k] > target)
				k--;
			else
				i++;
		}



	}

	return ans;
}
