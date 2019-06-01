/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.02%)
 * Total Accepted:    268.6K
 * Total Submissions: 536.6K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        if(s.size()==0)
            return -1;
        unordered_map<char , int> m;
        int len = s.size();
        for(int i=0; i<len; i++){
            m[s[i]]++;
        }
        for(int i=0; i<len; i++){
            if(m[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

