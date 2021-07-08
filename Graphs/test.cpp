#include<bits/stdc++.h>


using namespace std;


class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        
        queue<string> q;
        q.push(start);
        int wordsize=start.size();
        
        unordered_set<string> word;
        for(int i=0;i<wordList.size();i++){
            word.insert(wordList[i]);
        }
        
        if(word.find(end)==word.end()) return 0;
        
        int len=0;
        while(!q.empty()){
            len++;
            int qlen=q.size();
            for(int i=0;i<qlen;i++){
                string s=q.front();
                q.pop();
                for(int j=0;j<wordsize;j++){
                    char original=s[j];
                    for(char ch='a';ch<='z';ch++){
                        s[j]=ch;
                        if(s==end) return len+1;
                        if(word.find(s)==word.end()) continue;
                        
                        word.erase(s);
                        q.push(s);
                    }
                    s[j]=original;
                }
            }
        }
        return 0;
        
        
    }
};
int main(){

  vector<string> v({"hot","dot","lot","log"});
  cout<<solve("hit","cog",v);
}

