#include<bits/stdc++.h>


using namespace std;


    void addParents(string s, unordered_map<string, vector<string>> &parent, vector<string> &curr,vector<vector<string>> &ans, string A){
        curr.push_back(s);

        if(s == A){
            vector<string> rev(curr.rbegin(),curr.rend());
            ans.push_back(rev);
            rev.clear();
            curr.pop_back();
            return ;
        }

        for(auto p: parent[s]){
            addParents(p,parent,curr,ans,A);
        }

        curr.pop_back();

    }

    void findLadders(string A, string B, vector<string>& C) {
        queue<string> q;
        unordered_set<string> dict;
        unordered_set<string> rem;
        vector<vector<string>> ans;
        vector<string> curr;
        unordered_map<string,vector<string>> parent;
        bool stop = 0;

        for(auto s: C)
            dict.insert(s);

        q.push(A);

        if(!dict.count(B))
            return ;

        if(dict.count(A))
            dict.erase(A);

        while(!q.empty() && !stop){
            int sz = q.size();
            rem.clear();
            for(int k = 0; k < sz; k++){

                string s = q.front();

                for(int i = 0; i < s.length(); i++){
                    char org = s[i];
                    for(char x = 'a'; x <= 'z'; x++){
                        if(x == org)
                            continue;

                        s[i] = x;

                        if(dict.count(s)){
                            if(s == B) stop = 1;
                            if(!rem.count(s))
                                q.push(s);
                            rem.insert(s);
                            parent[s].push_back(q.front());
                         }
                    }
              
                    s[i] = org;
                }
                q.pop();

            }


            for(auto it: rem){
                dict.erase(it);
            }
        }


        addParents(B,parent,curr,ans,A);

        for(auto it: parent){
            cout<<"string "<<it.first<<"has parents ";
            for(auto ele: it.second)
                cout<<ele<<" ";
            cout<<endl;
        }

        // return ans;

        
     


    
    }

int main(){

  vector<string> v({"ted","tex","red","tax","tad","den","rex","pee"});
findLadders("red","tax",v);
}

