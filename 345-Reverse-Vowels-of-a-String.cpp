class Solution {
public:
    string reverseVowels(string s) {
        vector<int>vec;
        unordered_set<char>vowels={'a','A','e','E','i','I','o','O','u','U'};
        for(int i=0;i<s.size();++i){
            if(vowels.count(s[i]))
                vec.push_back(i);
        }
        int l=0,r=vec.size()-1;
        while(l<r){
            swap(s[vec[l]],s[vec[r]]);
            l++;
            r--;
        }
        return s;
    }
};