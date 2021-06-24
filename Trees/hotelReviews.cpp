vector<int> Solution::solve(string A, vector<string> &B) {
    unordered_map<string,bool> goodWords;
    map<int,vector<int>> mp; //#goodWords->v<indices>
    vector<int> ans;
    string goodWord = "";
    for(int i = 0; i < A.length(); i++){
        if(A[i] == '_'){
            goodWords[goodWord] = 1;
            goodWord = "";
        }
        else
            goodWord.push_back(A[i]);
    }

    goodWords[goodWord] = 1;
    goodWord = "";
    int idx = -1;
    for(string review: B){
        int cnt = 0;
        idx++;
        for(int i = 0; i < review.length(); i++){
            if(review[i] == '_'){
                if(goodWords.find(goodWord) != goodWords.end())
                    cnt++;
                goodWord = "";
            }
            else
                goodWord.push_back(review[i]);
        }
        if(goodWords.find(goodWord) != goodWords.end())
            cnt++;

        //or vector<pair<int,int>> cnt->index;
        //later sort the vector according to given conditions and add v[i].second to ans;
        mp[cnt].push_back(idx);
        goodWord = "";
    }
    

    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        vector<int> v = it->second;
        for(int index : v)
            ans.push_back(index);
    }

    return ans;


}
