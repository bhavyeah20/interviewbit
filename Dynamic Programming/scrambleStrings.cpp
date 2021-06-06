class Solution {
public:

    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return 1;

        int n = s1.length();

        if (n <= 1)
            return 0;

        for (int k = 1; k < n; k++) {
            if (isScramble(s1.substr(0, k), s2.substr(n - k))
                    && isScramble(s1.substr(k), s2.substr(0, n - k)))
                return 1;

            if (isScramble(s1.substr(0, k), s2.substr(0, k))
                    && isScramble(s1.substr(k), s2.substr(k)))
                return 1;
        }

        return 0;
    }
};

// memoized

class Solution {
public:

    unordered_map<string, bool> mp;

    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return 1;

        int n = s1.length();

        if (n <= 1)
            return 0;



        int count[26] = {0};
        for (int i = 0; i < n; i++)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 0)
                return false;
        }


        if (mp.find(s1 + " " + s2) == mp.end()) {

            mp[s1 + " " + s2] = 0;
            for (int k = 1; k < n; k++) {
                if (mp.find(s1.substr(0, k) + " " + s2.substr(n - k)) == mp.end())
                    mp[s1.substr(0, k) + " " + s2.substr(n - k)] = isScramble(s1.substr(0, k), s2.substr(n - k));

                if (mp.find(s1.substr(k) + " " + s2.substr(0, n - k)) == mp.end())
                    mp[s1.substr(k) + " " + s2.substr(0, n - k)] = isScramble(s1.substr(k), s2.substr(0, n - k));

                if (mp[s1.substr(0, k) + " " + s2.substr(n - k)] && mp[s1.substr(k) + " " + s2.substr(0, n - k)])
                    return mp[s1 + " " + s2] =  1;

                if (mp.find(s1.substr(0, k) + " " + s2.substr(0, k)) == mp.end())
                    mp[s1.substr(0, k) + " " + s2.substr(0, k)] = isScramble(s1.substr(0, k), s2.substr(0, k));

                if (mp.find(s1.substr(k) + " " + s2.substr(k)) == mp.end())
                    mp[s1.substr(k) + " " + s2.substr(k)] = isScramble(s1.substr(k), s2.substr(k));

                if (mp[s1.substr(0, k) + " " + s2.substr(0, k)] && mp[s1.substr(k) + " " + s2.substr(k)])
                    return mp[s1 + " " + s2] = 1;
            }
        }

        return mp[s1 + " " + s2];
    }
};