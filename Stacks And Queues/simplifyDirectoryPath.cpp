string Solution::simplifyPath(string A) {

	stack<string> s;
	string res = "/";
	for (int i = 0; i < A.size(); i++) {
		string dir = "";
		while (i < A.size() && A[i] == '/')
			i++;

		while (i < A.size() && A[i] != '/')
			dir.push_back(A[i]), i++;

		if (dir == "..") {
			if (!s.empty())
				s.pop();
		}

		else if (dir == ".")
			continue;

		else {
			if (dir.size() >= 1)
				s.push(dir);
		}


	}

	stack<string> s1;
	while (!s.empty()) {
		s1.push(s.top());
		s.pop();
	}


	while (!s1.empty()) {
		res += s1.top();
		s1.pop();
		if (s1.size() >= 1)
			res.push_back('/');

	}

	return res;
}

//or

// Use vectors instead of stack
string Solution::simplifyPath(string A) {

	vector<string> s;
	string res = "/";
	for (int i = 0; i < A.size(); i++) {
		string dir = "";
		while (i < A.size() && A[i] == '/')
			i++;

		while (i < A.size() && A[i] != '/')
			dir.push_back(A[i]), i++;

		if (dir == "..") {
			if (s.size())
				s.pop_back();
		}

		else if (dir == ".")
			continue;

		else {
			if (dir.size() >= 1)
				s.push_back(dir);
		}


	}




	for (int i = 0; i < s.size(); i++) {
		res += s[i];
		if (i != s.size() - 1)
			res.push_back('/');

	}

	return res;
}