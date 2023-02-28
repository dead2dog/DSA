// https://leetcode.cn/problems/valid-anagram/
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        if (s.size() != t.size()) return false;
        int record[26] = {0};
        auto size = s.size();
        for( int i = 0; i < size; i++)
        {
            record[s[i] - 'a']++;
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (record[i]) return false;
        }
        return true;
    }
};