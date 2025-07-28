class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //DFS Approach: TC & SC: O(m * n)
        int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++ ){
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    maxArea = max(maxArea, area);

                }
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int area = 1;

        area += dfs(grid, r + 1, c); //down
        area += dfs(grid, r - 1, c); //up
        area += dfs(grid, r , c + 1);//right
        area += dfs(grid, r , c - 1);//left

        return area;
    }


//     //BFS Approach : TC : O()
//     int rows = grid.size(), cols = grid[0].size();
//     int maxArea = 0;

//     for (int r = 0; r < rows; r++) {
//         for (int c = 0; c < cols; c++) {
//             if (grid[r][c] == 1) {
//                 maxArea = max(maxArea, bfs(grid, r, c));
//             }
//         }
//     }

//     return maxArea;
// }

// int bfs(vector<vector<int>>& grid, int r, int c) {
//     queue<pair<int, int>> q;
//     q.push({r, c});
//     grid[r][c] = 0; // mark visited
//     int area = 1;

//     vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

//     while (!q.empty()) {
//         auto [row, col] = q.front();
//         q.pop();

//         for (auto [dr, dc] : directions) {
//             int nr = row + dr;
//             int nc = col + dc;

//             if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) {
//                 grid[nr][nc] = 0; // mark visited
//                 q.push({nr, nc});
//                 area++;
//             }
//         }
//     }

//     return area;
// }
};
