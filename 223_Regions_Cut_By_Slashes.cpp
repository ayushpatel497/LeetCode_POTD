class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
        int v = (n + 1) * (n + 1);
        int e = n * 4;
        int c = 0;

        function<void(int, int)> dfs = [&](int r, int c) {
            visited[r][c] = 1;
            if (r == 0 || r == n) {
                if (c > 0 && !visited[r][c - 1]) dfs(r, c - 1);
                if (c < n && !visited[r][c + 1]) dfs(r, c + 1);
            }
            if (c == 0 || c == n) {
                if (r > 0 && !visited[r - 1][c]) dfs(r - 1, c);
                if (r < n && !visited[r + 1][c]) dfs(r + 1, c);
            }
            if (r < n && c < n && !visited[r + 1][c + 1] && grid[r][c] == '\\') dfs(r + 1, c + 1);
            if (r < n && c > 0 && !visited[r + 1][c - 1] && grid[r][c - 1] == '/') dfs(r + 1, c - 1);
            if (r > 0 && c < n && !visited[r - 1][c + 1] && grid[r - 1][c] == '/') dfs(r - 1, c + 1);
            if (r > 0 && c > 0 && !visited[r - 1][c - 1] && grid[r - 1][c - 1] == '\\') dfs(r - 1, c - 1);
        };

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i < n && j < n && grid[i][j] != ' ') e++;
                if (!visited[i][j]) {
                    c++;
                    dfs(i, j);
                }
            }
        }

        return e - v + c;
    }
};