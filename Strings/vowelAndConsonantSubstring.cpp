int Solution::solve(string s) {
    int mod = 1e9 + 7;
    int n = s.size();

    int vowel = 0, consonant = 0;

    if(s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1] == 'u')
        vowel = 1;
    else
        consonant = 1;


    int total = 0;

    for(int i = n - 2; i >= 0; i--){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vowel++;
            total = (total % mod + consonant % mod ) % mod;
            
        }

        else{
            consonant++;
            total = (total % mod +  vowel % mod) % mod;
        }
    }

    return total % mod;
}
