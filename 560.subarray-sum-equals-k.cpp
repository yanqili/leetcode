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
        std::unordered_map<long, vector<int>> map;

        long tmp=0;
        int result=0;
        long pre_sum = 0;
        int k_;
        for(int i=0; i<nums.size(); i++){
            tmp += nums[i];
            std::cout<<i<<endl;
            if(map.find(tmp) != map.end()){
                map[tmp].push_back(i);
            }
            else{
                vector<int> tmp_v;
                tmp_v.push_back(i);
                map[tmp] = tmp_v;
            }

            std::cout<<tmp<<" "<<endl;
        }
        std::cout<<"####"<<endl;
        std::unordered_map<long, vector<int>>::iterator itr;
        for(int i=0; i<nums.size(); i++){
            k_ = k + pre_sum;
            std::cout<<k_<<endl;
            itr = map.find(k_);
            if(itr != map.end()){
               for(int j=0; j<map[k_].size(); j++){
                    if(i <= map[k_][j])
                        result += 1;  
               }
               std::cout<<k_<<" result: "<<result<<endl;
            }
           pre_sum += nums[i];
    
        }
        return result;
    }
};

