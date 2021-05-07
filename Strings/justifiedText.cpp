string leftJustify(vector<string> &words, int diff, int i, int j) {
	/*We need to calculate spaces on right which is equal to
	character left - (j-i-1) which gives the space between the
	words */
	int spacesOnRight = diff - (j - i - 1);
	//Initialize the current string
	string result = words[i];
	//Then add rest of string seperated by single space
	for (int k = i + 1; k < j; k++) {
		result += " ";
		result.append(words[k]);
	}
	string ans = "";
	for (int m = 0; m < spacesOnRight; m++) {
		result += " ";
	}
	return result;
}

string middleJustify(vector<string> &words, int diff, int i, int j) {
	//(j-i-1) which gives the space between the words
	int spacesNeeded = j - i - 1;

	//To evenly distribute spaces between words
	int spaces = diff / spacesNeeded;

	//Extra spaces which are to be appended at left
	int extraSpaces = diff % spacesNeeded;
	//Initialize the current string
	string result = words[i];
	for (int k = i + 1; k < j; k++) {
		int spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
		for (int m = 0; m < spacesToApply; m++) {
			result += " ";
		}
		result.append(words[k]);
	}
	return result;
}
vector<string> Solution::fullJustify(vector<string> &words, int maxWidth) {
	vector<string> res;
//There are two pointers i and j. j is one step ahead of i.
	int i = 0, n = words.size();
	while (i < n) {
		int j = i + 1;
		//Stores the length of word upto the point i points
		int charLen = words[i].size();
		//Move j pointer forward upto the point where no of characters is greater than maxwidth
		//(j-i) gives the no of words and (j-i-1) gives the space between the words
		while (j < n && (charLen + words[j].length() + (j - i - 1) < maxWidth)) {
			//charLen only calculates the word character length
			charLen += words[j].length();
			++j;
		}
		int diff = maxWidth - charLen;
		int numberOfWords = j - i;
		if ( numberOfWords == 1 || j >= n) {
			res.push_back(leftJustify(words, diff, i, j));
		} else {
			res.push_back(middleJustify(words, diff, i, j));
		}
		//20184165
		//Before j the character length of words can be accomodated in a line
		i = j;
	}
	return res;
}


// or


// void convert(string s, int len, vector<string> &ans, int words, int cnt) {
// 	int spacesToDistribute = len - cnt;
// 	int gap = words - 1;
// 	if (gap) {
// 		int space = spacesToDistribute / gap;
// 		int mod = spacesToDistribute % gap;
// 		for (int i = 0; i < s.size(); i++) {
// 			if (s[i] == ' ') {
// 				s.insert(i, space - 1, ' ');
// 				i += space - 1;
// 			}
// 		}
// 		if (mod) {
// 			int currMod = 0;
// 			for (int i = 0; i < s.size(); i++) {
// 				if (s[i] == ' ') {
// 					while (s[i] == ' ') {
// 						i++;
// 					}
// 					s.insert(i, 1, ' ');
// 					currMod++;
// 					if (currMod == mod)
// 						break;
// 				}
// 			}
// 		}
// 	}
// 	else {
// 		int space = spacesToDistribute;
// 		s.insert(s.size(), space, ' ');
// 	}
// 	ans.push_back(s);
// }

// vector<string> fullJustify(vector<string> &A, int len) {
// 	vector<string> ans;
// 	if (!A.size())
// 		return ans;
// 	string ians = "";
// 	int currLen = 0;
// 	int words = 0;
// 	int chars = 0;
// 	for (int i = 0; i < A.size(); i++) {
// 		string x = A[i];
// 		currLen += x.size();
// 		if (currLen <= len) {
// 			ians += x;
// 			words++;
// 			chars += x.size();
// 			if (currLen == len || currLen + 1 == len) {
// 				convert(ians, len, ans, words, chars);
// 				ians = "";
// 				currLen = 0;
// 				words = 0;
// 				chars = 0;
// 				continue;
// 			}
// 			if (i == A.size() - 1) {
// 				convert(ians, len, ans, words, chars);
// 				break;
// 			}
// 			else
// 				currLen++, ians += " ";
// 		}
// 		else {
// 			currLen -= x.size();
// 			if (ians[ians.size() - 1] == ' ')
// 				ians.erase(ians.size() - 1, 1);
// 			convert(ians, len, ans, words, chars);
// 			ians = "";
// 			currLen = 0;
// 			words = chars = 0;
// 			i--;
// 			continue;
// 		}
// 	}
// 	int m = ans.size();
// 	string s = ans[m - 1];
// 	stringstream ss(s);
// 	int word = 0;
// 	while (ss >> s)
// 		word++;
// 	if (word == 1) {
// 		return ans;
// 	}
// 	s = ans[m - 1];
// 	int i = 0;
// 	int j = s.size() - 1;
// 	while (i < m && s[i] == ' ') {
// 		i++;
// 	}
// 	s.erase(0, i);
// 	while (j >= 0  && s[j] == ' ') {
// 		j--;
// 	}
// 	s.erase(j + 1);
// 	for (int i = 0; i < s.size(); i++) {
// 		if (s[i] == ' ') {
// 			int j = i;
// 			while (s[j] == ' ')
// 				j++;
// 			s.erase(i, j - i - 1);
// 		}
// 	}
// 	s.insert(s.size(), len - s.size(), ' ');
// 	ans[m - 1] = s;
// 	return ans;
// }
