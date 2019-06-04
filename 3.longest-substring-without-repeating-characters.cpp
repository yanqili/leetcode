/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.37%)
 * Total Accepted:    936.3K
 * Total Submissions: 3.3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int start=0;
        int max_len = -1;
        unordered_map<char, int> m;
        int i;
        for(i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end()){ //出现过
                if(m[s[i]] < start){ // 在字符串外重复
                    m[s[i]] = i;                   
                }
                else{  //否则更新子串
                    if((i-start)>max_len)
                        max_len = i-start;
                    start = m[s[i]]+1;
                    m[s[i]] = i;                   
                }    
            }
            else{
                m[s[i]] = i;
            }
        }
        if((i-start)>max_len) //最后一个子串
            max_len = i-start;
        return max_len;

    }
};

