/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int sum_left = 0;
        int sum_right = 0;
        int sum = 0;
        int max_left = -1;
        int max_right = -1;
        for(int i=0; i < height.size(); i++){
            if(height[i]>max_left){
                max_left = height[i];
                
            }
            sum_left += max_left;
            sum += height[i];
        }
        
        for(int j=height.size()-1; j >= 0; j--){
            if(height[j]>max_right){
                max_right = height[j];
                
            }
            sum_right += max_right;
        }
        
        return sum_left + sum_right -max_left * height.size() - sum;
    }
};
