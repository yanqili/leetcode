/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.23%)
 * Total Accepted:    644.5K
 * Total Submissions: 2.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
#include<queue>
#include <math.h> 
class Solution {
public:
    int reverse(int x) {
        //std::queue<int> que;
        int minus = 1;
        long result = 0;
        long _x = x;
        if(_x < 0)
        {
            minus = -1;
            _x = _x * -1;
        }            
        while(_x!=0)
        {
           int tmp = _x%10;
           _x = _x/10;
           result = result * 10 + tmp;
        }
        if(minus == -1)
        {
            if(result*minus < -pow(2,31))
                return 0;
        }
        else
        {
            if(result*minus > pow(2,31) - 1)
                return 0;
        }
        return result*minus;
        
    }
};

