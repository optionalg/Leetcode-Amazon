class UnionFind{
private:
    vector<int> parents;
public:
    UnionFind(const int n){
        parents.resize(n, 0);
        for(int i = 0; i < n; ++i)
            parents[i] = i;
    }
    bool Union(int i, int j){
        int pi = Find(i), pj = Find(j);
        if(pi == pj) return false;
        parents[pj] = pi;
        return true;
    }
    int Find(int i){
        while(i != parents[i]){
            i = parents[i];
        }
        return i;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        const size_t m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    cnt++;
                    if(j > 0 && grid[i][j - 1] == '1' && uf.Union(i * n + j, i * n + j - 1))
                        cnt--;
                    if(i > 0 && grid[i - 1][j] == '1' && uf.Union(i * n + j, (i - 1) * n + j))
                        cnt--;
                }
            }
        }
        return cnt;
    }
};
