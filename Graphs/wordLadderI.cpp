class Solution {
public:
    int ladderLength(string A, string B, vector<string>& C) {
	  	queue<string> q;
	  	unordered_map<string,bool> dict;
	 	unordered_map<string,bool> vis;
	  	int moves = 1;

	  	for(auto s: C)
	    	dict[s] = 1;

	  	q.push(A);
	  	vis[A] = 1;

	  	while(!q.empty()){
	    	int sz = q.size();
	    	for(int k = 0; k < sz; k++){

	      		string s = q.front();
	      		q.pop();

	      		for(int i = 0; i < s.length(); i++){
	          		char org = s[i];
	        		for(char x = 'a'; x <= 'z'; x++){
			        	if(x == org)
			            	continue;

	          			s[i] = x;

	          			if(!vis[s] && dict[s]){
	          				if(s == B) return moves+1;
	            			vis[s] = 1;
	            			q.push(s);
	         			 }
	       			}
	          
	          		s[i] = org;
	     		}
	    	}

	    	moves++;
	  }
	     
		return 0;	
	}
};

//

class Solution {
public:
    int ladderLength(string A, string B, vector<string>& C) {
	  	queue<string> q;
	  	unordered_set<string> dict;
	  	int moves = 1;

	  	for(auto s: C)
	    	dict.insert(s);

	  	q.push(A);

	  	if(!dict.count(B))
	  		return 0;

	  	while(!q.empty()){
	    	int sz = q.size();
	    	for(int k = 0; k < sz; k++){

	      		string s = q.front();
	      		q.pop();

	      		for(int i = 0; i < s.length(); i++){
	          		char org = s[i];
	        		for(char x = 'a'; x <= 'z'; x++){
			        	if(x == org)
			            	continue;

	          			s[i] = x;

	          			if(dict.count(s)){
	          				if(s == B) return moves+1;
	          				dict.erase(s);
	            			q.push(s);
	         			 }
	       			}
	          
	          		s[i] = org;
	     		}
	    	}

	    	moves++;
	  }
	     
		return 0;	
	}
};