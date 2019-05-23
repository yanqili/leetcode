/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (39.07%)
 * Total Accepted:    140.5K
 * Total Submissions: 358.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
#include <math.h>
class Solution {
public:
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n == 1){
            vector<string> tmp;
            tmp.push_back("Q");
            result.push_back(tmp);
            return result;
        }
        else if(n <=3)
            return result;
        int * record = new int[n];
        process(0,record,result,n);
        return result;
    }
    void process(int row, int* record, vector<vector<string>>& result, const int n){
        if(row == n){
            vector<string> tmp = convert_to_string(record,n);
            result.push_back(tmp);
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(record, row, i)){
                record[row] = i;
                process(row+1, record, result, n);
            }
        }
    }
    bool isValid(int* record, int row, int col){
        for(int i = 0; i<row; i++){
            if(record[i] == col)
                return false;
            else if(abs(i-row) == abs(record[i]-col)){
                return false;
            }
        }
        return true;
    }
    vector<string> convert_to_string(int* record, const int n){
        vector<string> tmp;
        for(int i=0; i<n; i++){
            string str(n, '.');
            str[record[i]] = 'Q';
            tmp.push_back(str);
        }
        return tmp;
    }


};

