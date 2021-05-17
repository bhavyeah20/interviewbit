int Solution::braces(string A) {
	stack<char> s;
	for (char x : A) {
		if (x != ')')
			s.push(x);

		else {
			int cnt = 0;

			while (!s.empty() && s.top() != '(')
				s.pop(), cnt++;
			s.pop();



			if (cnt <= 1)
				return 1;


			//case like
			// ((a+b)*(c+d))
		}
	}


	return 0;
}
