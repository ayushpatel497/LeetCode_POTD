class Solution {
private:
    bool check(vector<vector<char>>& board, const string& word, int index, int row, int col) {
        if (index == word.length())
            return true;
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '*';

        bool ans = check(board, word, index + 1, row + 1, col) ||
                     check(board, word, index + 1, row - 1, col) ||
                     check(board, word, index + 1, row, col + 1) ||
                     check(board, word, index + 1, row, col - 1);

        board[row][col] = temp;
        return ans;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty())
            return true;

        int m = board.size();
        int n = board[0].size();
        if (!m || !n)
            return false;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (check(board, word, 0, i, j))
                    return true;
        return false;
    }
};