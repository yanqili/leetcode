/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (42.83%)
 * Total Accepted:    1.6M
 * Total Submissions: 3.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_index;
        vector<int> result;
        int i;
        for(i = 0;i < nums.size();i++){
            int tmp = target - nums[i];
            auto iter = num_index.find(tmp);
            if(iter != num_index.end()){ // 若匹配的另外一个值在该值的左边，则必然在map里
                result.push_back(i);
                result.push_back(iter->second);
                return result;
            }
            else{ //若匹配的另外一个值在该值的右边，则将该值放进map里，等待被找到
                num_index[nums[i]] = i;
            }
        }
        return result;
    }
};

