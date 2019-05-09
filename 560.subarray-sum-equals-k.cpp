/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (41.90%)
 * Total Accepted:    98.2K
 * Total Submissions: 233.1K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;

        int tmp=0;
        int result=0;
        map[0] = 1;
        for(int i=0; i<nums.size(); i++){
            tmp += nums[i];
            if(map.find(tmp - k) != map.end()){
                result += map[tmp - k];
            }
            if(map.find(tmp) != map.end()){
                map[tmp] += 1;
            }
            else{
                map[tmp] = 1;
            }
        }

        return result;
    }
};

