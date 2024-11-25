class Solution {
    string swap(string s, int i, int j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        return s;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2, n = 3;
        string target = "123450";
        string start = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                start += to_string(board[i][j]);
            }
        }
        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                            {0, 4}, {3, 1, 5}, {4, 2}};
        queue<string> q;
        unordered_set<string> visited;
        q.push(start);
        visited.insert(start);
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                if (target == curr) {
                    return steps;
                }
                int emptyIdx = 0;
                for (; curr[emptyIdx] != '0'; emptyIdx++)
                    ;
                for (int neighborIdx : neighbors[emptyIdx]) {
                    string new_board = swap(curr, neighborIdx, emptyIdx);
                    if (!visited.count(new_board)) {
                        q.push(new_board);
                        visited.insert(new_board);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};