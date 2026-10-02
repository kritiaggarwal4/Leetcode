class Solution {
public:
  bool solve(int i, int j, vector<vector<char>>& board, string &word, int index){
    int n = board.size();
    int m = board[0].size();
    if(index == word.length()){
        return true;
    }
    if(i<0 || i>=n || j<0 || j>=m|| board[i][j]!=word[index])
    return false;
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = solve(i+1, j, board, word, index+1)|| solve(i-1, j, board, word, index+1)|| solve(i, j+1, board, word, index+1)|| solve(i, j-1, board, word, index+1);
    board[i][j] = temp;
    return found;
  }
    bool exist(vector<vector<char>>& board, string word) {
       for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {

            if(solve(i, j, board, word, 0))
                return true;
        }
    }

    return false;
    }
};