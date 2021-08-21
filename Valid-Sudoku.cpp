/**
Time = O(n^2)
Space = O(n^2)
**/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        bool checkRow[9][9] = {0};
        bool checkCol[9][9] = {0};
        bool checkBox[9][9] = {0};
        
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]!='.'){
                    int digit = board[i][j]-'1';
                    int k = i/3*3+j/3;
                    // cout << k << endl;
                    if(checkRow[i][digit] || checkCol[j][digit] || checkBox[k][digit]){
                        return false;
                    }
                    checkRow[i][digit] = 1;
                    checkCol[j][digit] = 1;
                    checkBox[k][digit] = 1;
                    
                }
            }
        }
        return true;
    }
};
