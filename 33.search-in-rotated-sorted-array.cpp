/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.88%)
 * Total Accepted:    414K
 * Total Submissions: 1.3M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int find_1(vector<int>& nums, int target, int L, int R){
        if(L > R)
            return -1;
        int mid = (L+R)/2;
        if(nums[mid] == target)
            return mid;
        if(target > nums[mid])
            return find_1(nums, target, mid+1, R);
        else
            return find_1(nums, target, L, mid-1);
    }
    int find_2(vector<int>& nums, int target, int L, int R){
        if(L > R)
            return -1;
        if(nums[L]<nums[R])
            return find_1(nums, target, L, R);
        int mid = (L+R)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] >= nums[L]) // mid在左部分
        {
            if(target < nums[mid] && target >= nums[L])
                return find_1(nums, target, L, mid-1);
            else
                return find_2(nums, target, mid+1, R);
        }
        else
        {
            if(target > nums[mid] && target <= nums[R])
                return find_1(nums, target, mid+1, R);
            else
                return find_2(nums, target, L, mid-1);
        }
    }
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <=0 )
            return -1;
        if(nums[0]<nums[len-1])
            return find_1(nums, target, 0, len-1);
        
        else{
            return find_2(nums, target, 0, len-1);
        }
    }
};

