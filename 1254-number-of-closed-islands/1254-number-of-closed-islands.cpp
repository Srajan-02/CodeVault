class Solution {
public:
    int m,n;
    bool dfs(vector<vector<int>>& grid,int row,int col){
        if(row>=m || row<0 || col>=n || col<0){ //out of bond
            return false;
        }
        if(grid[row][col]==1){ //water milgya
            return true; //closed from one side.
        }
        grid[row][col]=1;// visited
        bool left_closed = dfs(grid,row,col-1);
        bool right_closed = dfs(grid,row,col+1);
        bool up_closed = dfs(grid,row-1,col);
        bool down_closed = dfs(grid,row+1,col);

        return left_closed && right_closed && up_closed && down_closed; // close island condition

    }
    
    int closedIsland(vector<vector<int>>& grid){
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){ //land
                    if(dfs(grid,i,j)==true){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
};