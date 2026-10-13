class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int >freq1(26,0);
        vector<int> freq2(26,0);

        for(int i=0; i<s.length();i++){
            freq1[s[i]-'a']++;
        }
        for(int i=0; i<t.length();i++){
            freq2[t[i]-'a']++;
        }
        for(int i = 0 ; i<26; i++){
            if(freq1[i] != freq2[i]){
                return char( i+'a');
            }
        }
        return '\0';
    }
};