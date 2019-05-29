/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.62%)
 * Total Accepted:    347.1K
 * Total Submissions: 974.6K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
class Solution {
public:
    void swap_(vector<vector<int>> & intervals, int i, int j){
        vector<int> tmp = intervals[i];
        intervals[i] = intervals[j];
        intervals[j] = tmp;
        //cout<<"swap"<<i<<" "<<j<<endl;
    }
    bool compare_(vector<vector<int>> & intervals, int i, int j){
        if(intervals[i][0] <= intervals[j][0])
            return true;
        else
            return false;
    }
    void quick_sort(vector<vector<int>> & intervals, int L, int R){

        if(L >= R)
            return;
        int mid = (L+R)/2;
        swap_(intervals, mid, R);
        int i;
        int j = L;
        for(i = L; i<R; i++){
            if(compare_(intervals,i,R)){
                swap_(intervals,i,j);
                j++;
            }
        }
        swap_(intervals,R,j);
        
        quick_sort(intervals, L, j-1);
        quick_sort(intervals, j+1, R);


    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> result;
        if(intervals.size()==0)
            return result;
        if(intervals.size()==1)
            return intervals;
        quick_sort(intervals, 0, intervals.size()-1);
        
        for(int i=0; i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
        vector<int> tmp = intervals[0];
        
        for(int i=1; i<= intervals.size()-1; i++){
            if(intervals[i][0] <= tmp[1]){
                if(intervals[i][1] > tmp[1])
                    tmp[1] = intervals[i][1];
            }
            else{
                result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        result.push_back(tmp); //最后一个
        return result;
    }
};

