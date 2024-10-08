class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> rowSet;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (rowSet.find(board[i][j]) != rowSet.end()) {
                        return false;
                    }
                    rowSet.insert(board[i][j]);
                }
            }
        }

        for (int j = 0; j < 9; ++j) {
            unordered_set<char> colSet;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] != '.') {
                    if (colSet.find(board[i][j]) != colSet.end()) {
                        return false;
                    }
                    colSet.insert(board[i][j]);
                }
            }
        }

        for (int block = 0; block < 9; block++) {
            unordered_set<char> blockSet;
            for (int i = block / 3 * 3; i < block / 3 * 3 + 3; i++) {

                for (int j = block % 3 * 3; j < block % 3 * 3 + 3; j++) {

                    if (board[i][j] != '.') {
                        if (blockSet.find(board[i][j]) != blockSet.end()) {
                            return false;
                        }
                        blockSet.insert(board[i][j]);
                    }

                }
            }
        }

        return true; 
    }
};