/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.39%)
 * Total Accepted:    577.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m['('] = ')';
        m['['] = ']';
        m['{'] = '}';
        stack<char> st;
        if(s.size() == 0)
            return true;
        for(int i = 0; i<s.size(); i++){
            if(st.size() == 0)
                st.push(s[i]);
            else{
                if(s[i] == m[st.top()])
                    st.pop();
                else
                    st.push(s[i]);
            }
            
        }
        if(st.size() == 0)
            return true;
        return false;
    }
};

