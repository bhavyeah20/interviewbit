vector<string> Solution::prettyJSON(string A) {

	int cntBrackets = 0;

	int n = A.size();
	vector<string> ans;
	string temp = "";
	for (int i = 0; i < n; i++) {
		char x = A[i];
		if (x == '{' || x == '[') {
			if (i) {
				ans.push_back(temp);
				temp = "";
			}

			for (int j = 0; j < cntBrackets; j++)
				temp.push_back('\t');
			cntBrackets++;
			temp.push_back(x);
			ans.push_back(temp);
			temp = "";
			for (int j = 0; j < cntBrackets; j++)
				temp.push_back('\t');
		}

		else if (x == '}' || x == ']') {
			cntBrackets--;
			ans.push_back(temp);
			temp = "";

			for (int j = 0; j < cntBrackets; j++)
				temp.push_back('\t');
			temp.push_back(x);
			if (i < n - 1 && A[i + 1] != ',') {
				ans.push_back(temp);
				temp = "";
			}
		}

		else if (x == ',') {
			temp.push_back(x);
			ans.push_back(temp);
			temp = "";
			for (int j = 0; j < cntBrackets; j++)
				temp.push_back('\t');
		}

		else
			temp.push_back(x);
	}

	return ans;

}



