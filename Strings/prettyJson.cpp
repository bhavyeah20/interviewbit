vector<string> Solution::prettyJSON(string A) {

	int cntBrackets = 0;

	int n = A.size();
	vector<string> ans;
	string temp = "";
	for (int i = 0; i < n; i++) {
		char x = A[i];
		if (x == '{' || x == '[') {
			if (i) {
				if (!temp.empty())
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
			if (!temp.empty())
				ans.push_back(temp);
			temp = "";

			for (int j = 0; j < cntBrackets; j++)
				temp.push_back('\t');
			temp.push_back(x);
			if ((i < n - 1 && A[i + 1] != ',') || i == n - 1) {
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



class Solution {
public:
	vector<string> prettyJSON(string json) {
		vector<string> ans;
		if (json.length() == 0) return ans;
		// remove all spaces.
		json.erase(remove(json.begin(), json.end(), ' '), json.end());

		string indent = "";
		string current = "";
		int i = 0, len = json.length();
		while (i < len) {
			current.push_back(json[i]);
			switch (json[i]) {
			case ',':
				ans.push_back(current);
				current = indent;
				i++;
				break;
			case ':':
				i++;
				if (json[i] == '{' || json[i] == '[') {
					ans.push_back(current);
					current = indent;
				}
				break;
			case '{':
			case '[':
				i++;
				ans.push_back(current);
				if (i < len && (json[i] != '}' || json[i] != ']')) {
					indent.push_back('\t');
				}
				current = indent;
				break;
			case '}':
			case ']':
				i++;
				if (i < len && json[i] == ',') break;
				ans.push_back(current);
				if (i < len && (json[i] == '}' || json[i] == ']')) {
					if (!indent.empty()) indent.pop_back();
				}
				current = indent;
				break;
			default :
				i++;
				if (i < len && (json[i] == '}' || json[i] == ']')) {
					ans.push_back(current);
					if (!indent.empty()) indent.pop_back();
					current = indent;
				}
			}
		}
		return ans;
	}
};