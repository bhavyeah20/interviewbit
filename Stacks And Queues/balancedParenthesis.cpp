bool match(char x, char y) {
	if (x == '(' && y == ')')
		return 1;

	if (x == '[' && y == ']')
		return 1;

	if (x == '{' && y == '}')
		return 1;

	return 0;

}


int Solution::isValid(string A) {
	stack<char> s;


	for (char y : A) {
		if (y == '(' || y == '[' || y == '{')
			s.push(y);

		else {
			if (s.empty())
				return 0;

			if (!match(s.top(), y))
				return 0;

			s.pop();
		}
	}

	if (s.empty())
		return 1;

	return 0;
}
