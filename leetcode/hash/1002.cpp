// https://leetcode.cn/problems/find-common-characters/
#include<cstring>
#include<vector>
#include<string>
#include <algorithm> 

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<std::string> res;
        if (words.size() == 0) return res;
        int hash[26] = {0};
        int hash_ptr[26] = {0};
        
        for (int i = 0 ; i < words[0].size(); i++)
        {
            hash[words[0][i] - 'a']++;
        }

        for(int i = 1; i < words.size(); i++)
        {
            memset(hash_ptr,0,26 * sizeof(int));
            for(int j = 0; j< words[i].size(); j++)
            {
                hash_ptr[words[i][j] - 'a']++;
            }

            for(int j = 0; j < 26; j++)
            {
                hash[j] = std::min(hash[j], hash_ptr[j]);
            }
        }
        
        for(int i = 0; i<26;i++)
        {
            while(hash[i] != 0 )
            {
                std::string s(1,i + 'a');
                res.push_back(s);
                hash[i]--;
            }
        }
        return res;
    }
};