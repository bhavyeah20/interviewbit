vector<vector<int> > Solution::anagrams(const vector<string> &A) {

	unordered_map<string, vector<int> > mp;

	unordered_map<string, bool> tally;

	for (int i = 0; i < A.size(); i++) {
		string s = A[i];
		sort(s.begin(), s.end());
		mp[s].push_back(i + 1);
	}

	vector<vector<int> > ans;

	for (int i = 0; i < A.size(); i++) {
		string s = A[i];
		sort(s.begin(), s.end());
		if (tally[s]) {
			continue;
		}

		else {
			tally[s] = 1;
			ans.push_back(mp[s]);
		}

	}

	return ans;

}


//or


vector<vector<int> > Solution::anagrams(const vector<string> &A) {

	unordered_map<string, vector<int> > mp;

	for (int i = 0; i < A.size(); i++) {
		string s = A[i];
		sort(s.begin(), s.end());
		mp[s].push_back(i + 1);
	}

	vector<vector<int> > ans;

	for (auto it = mp.begin(); it != mp.end(); it++) {
		ans.push_back(it->second);
	}

	// for(auto it : mp)
	// 	ans.push_back(it.second);


	return ans;

}


// Count sort
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		for (string s : strs) {
			mp[strSort(s)].push_back(s);
		}
		vector<vector<string>> anagrams;
		for (auto p : mp) {
			anagrams.push_back(p.second);
		}
		return anagrams;
	}
private:
	string strSort(string s) {
		int counter[26] = {0};
		for (char c : s) {
			counter[c - 'a']++;
		}
		string t;
		for (int c = 0; c < 26; c++) {
			t += string(counter[c], c + 'a');
		}
		return t;
	}
};