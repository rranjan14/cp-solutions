/*
1219. Path with Maximum Gold

In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:
    1.Every time you are located in a cell you will collect all the gold in that cell.
    2.From your position you can walk one step to the left, right, up or down.
    3.You can't visit the same cell more than once.
    4.Never visit a cell with 0 gold.
    5.You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Example 2:
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
*/

class Solution {
public:
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    int ans = 0,r=0,c=0;
    void solve(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& visited,int sum){
        // cout << ans << " "<<sum << " "<<row << " " << col << "\n";
        ans = max(ans,sum);
        for(int i=0;i<4;i++){
            if(row+dx[i]>=0 &&row+dx[i]<r && col+dy[i]>=0 && col+dy[i]<c){
            if(grid[row+dx[i]][col+dy[i]]!=0 && !visited[row+dx[i]][col+dy[i]]){
                sum+=grid[row+dx[i]][col+dy[i]];
                visited[row+dx[i]][col+dy[i]]=true;
                solve(row+dx[i],col+dy[i],grid,visited,sum);
                sum-=grid[row+dx[i]][col+dy[i]];
                visited[row+dx[i]][col+dy[i]]=false;
            }
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    visited[i][j]=true;
                    solve(i,j,grid,visited,0+grid[i][j]);
                    visited[i][j]=false;
                }
            }
        }
        return ans;
    }
};