class Solution {
public:
    int dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, -1, 1};
    void BFS(int i, int j, vector<vector<bool>> &visited, const vector<vector<char>> &grid){
        const size_t m = grid.size(), n = grid[0].size();
        int r, c, x, y;
        queue<int> q;
        q.push(i * n + j);
        while(!q.empty()){
            r = q.front() / n;
            c = q.front() % n;
            q.pop();
            for(int k = 0; k < 4; ++k){
                x = c + dirx[k], y = r + diry[k];
                if(x >= 0 && x < n && y >= 0 && y < m && !visited[y][x]){
                    if(grid[y][x] == '1')
                        q.push(y * n + x);
                    visited[y][x] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        const size_t m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(visited[i][j]) continue;
                visited[i][j] = true;
                if(grid[i][j] == '1'){
                    cnt++;
                    BFS(i, j, visited, grid);
                }
                    
            }
        }
        return cnt;
    }
};
