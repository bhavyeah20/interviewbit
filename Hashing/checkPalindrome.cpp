int Solution::solve(string A) {
	unordered_set<char> s;

	for(char x: A){
		if(s.count(x))
			s.erase(x);
		else
			s.insert(x);
	}

	return s.size() == 0 || s.size() == 1;
}
