class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // for each raw
        for (int i = 0; i < n; ++i) {
            set<char> st;
            for (int j = 0; j < m; ++j) {
                if (board[i][j] != '.') {
                   if(st.find(board[i][j]) != st.end()) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        // for each col
        for (int i = 0; i < n; ++i) {
            set<char> st;
            for (int j = 0; j < m; ++j) {
                if (board[j][i] != '.') {
                  if(st.find(board[j][i]) != st.end()) return false;
                    st.insert(board[j][i]);
                }
            }
        }
        // for each subarr size 3 * 3
        set<char> st;
        for (int raw = 0; raw < n; raw += 3) {
            for (int col = 0; col < m; col += 3) {
                set<char> st;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (board[raw + i][col + j] != '.') {
                             if (st.find(board[raw + i][col + j]) != st.end()) return false;  
                             st.insert((board[raw + i][col + j]));
                        }
                    }
                }
            }
        }
        return true;
    }
};