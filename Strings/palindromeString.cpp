int val(char x) {
	if (x <= 'z' && x >= 'a')
		return x - 'a';
	if (x >= '0' && x <= '9')
		return x - '0';
	if (x <= 'Z' && x >= 'A')
		return x - 'A';
}

int Solution::isPalindrome(string A) {
	string s = "";
	for (char x : A) {
		if ((x <= 'z' && x >= 'a') || (x >= '0' && x <= '9') || (x <= 'Z' && x >= 'A'))
			s.push_back(x);
	}

	int n = s.size();
	int mid = (n - 1) / 2;
	int flag = 0;

	for (int i = 0; i <= mid; i++) {

		if (val(s[i]) != val(s[n - i - 1])) {
			return 0;
		}
	}

	return 1;
}

// or

// class Solution {
// public:
// 	bool isPalindrome(string s) {

// 		int i = 0, j = (int)s.size() - 1;
// 		while (i < j)
// 		{
// 			while (i < j && !isalnum(s[i])) i++;
// 			while (i < j && !isalnum(s[j])) j--;
// 			if (toupper(s[i]) != toupper(s[j])) return false;
// 			i++;
// 			j--;
// 		}
// 		return true;
// 	}

// };