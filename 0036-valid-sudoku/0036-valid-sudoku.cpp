#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 2D arrays to track seen digits (mapped from '1'-'9' to indices 0-8)
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};
        
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue; // Skip empty cells
                }
                
                // Map the character digit to an integer index (0 to 8)
                int val = board[r][c] - '1'; 
                
                // Calculate which of the 9 sub-boxes this cell belongs to
                int box_index = (r / 3) * 3 + (c / 3);
                
                // If the digit has already been seen in the current row, column, or box, it's invalid
                if (rows[r][val] || cols[c][val] || boxes[box_index][val]) {
                    return false;
                }
                
                // Mark the digit as seen
                rows[r][val] = true;
                cols[c][val] = true;
                boxes[box_index][val] = true;
            }
        }
        
        return true;
    }
};