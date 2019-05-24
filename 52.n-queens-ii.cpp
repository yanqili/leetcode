/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (51.75%)
 * Total Accepted:    98.7K
 * Total Submissions: 190.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    void process(int row, int* record, int &result, const int n){
        if(row == n){
            result++;
            return;
        }
        for(int i=0; i<n; i++){
            if(isValid(record,row,i)){
                record[row] = i;
                process(row+1, record, result, n);
            }
        }
    }
    bool isValid(int* record, const int row, const int col){
        for(int i=0; i<row ; i++){
            if(record[i] == col)
                return false;
            else if(abs(row - i) == abs(col - record[i]))
                return false;
        }
        return true;
    }
    int totalNQueens(int n) {
        if(n==1)
            return 1;
        else if(n<=3)
            return 0;
        int result = 0;
        int* record = new int[n];
        process(0,record,result,n);
        return result;
    }
};

