int Solution::longestConsecutive(const vector<int> &A) {
  unordered_set<int> s;
    for(auto it: A)
        s.insert(it);

    int maxx = 0, cnt = 0;
    for(auto it: s){
        cnt = 0;
        if(!(s.count(it-1))){
            cnt++;
            while(s.count(it+1)){
                cnt++;
                it++;
            }

            maxx = max(maxx,cnt);
        }
    }

    return maxx;
}
