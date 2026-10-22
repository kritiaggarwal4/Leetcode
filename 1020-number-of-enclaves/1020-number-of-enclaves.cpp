class Solution {
    private:
    void dfs(int row,int col, vector<vector<int>>&grid){
        grid[row][col] =0;
         int m = grid.size();
        int n = grid[0].size();
     
        int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for(auto &d:dir){
            int nr = row+d[0];
            int nc = col+d[1];
            if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                dfs(nr,nc,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
      for(int i=0;i<n;i++){ //rows boundary check
     if(grid[0][i] == 1 ){
        dfs(0,i,grid);
     }
     if(grid[m-1][i] == 1){
        dfs(m-1, i,grid);
     }
      }
     for(int j=0;j<m;j++) { //cols boundary check
         if(grid[j][0] == 1){
            dfs(j,0,grid);
         }
         if(grid[j][n-1] ==1 ){
            dfs(j,n-1,grid);
         }
     }
     int count =0;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1 ){
                count++;
            }
        }
     }
     return count ;
    }
};