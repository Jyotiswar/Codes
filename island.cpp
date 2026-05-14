#include<iostream>
#include<vector>
using namespace std;
class solution{
    //the index is valid or not 
    bool valid(int i, int j, int m, int n){
        
        if(i < 0 ||  i >= n && j < 0 || j >= m){
            return false;
        }
        return true;

    }
    //dfs search if dfs valid
    void dfs(vector<vector<char>>& grid,int n, int m, int i, int j, vector<vector<bool>>&vis){

        //after jumping down mark it
        vis[i][j] = 1;
        //intialize x and y axis to explore (which are the ways i want to go from here way)
        int x[]= {-1, 1 , 0 ,0};
        int y[] = {0,0,-1,1};

        for(int k = 0 ; k < 4 ; k++){
            //fetching the rows and columns, taking the ways  
            int row = i + x[k];
            int column = i + y[k];
            //after taking the ways we need to  check them
            //we use valid function to check the water
            //then we check by the visited array 
            if(valid(row,column,m,n) && grid[row][column] == '1' && vis[row][column] == 0){
                dfs(grid, n, m, row, column, vis);
            }
        }
        return;

    }

    //calls the dfs function
    int numIsland(vector<vector<char>>& grid ){
        
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>>vis(n);

        //short form of creating a 2d array filled with zeros -- > vector<vector<bool>>visited(n,vector<bool>m)

        for(int i = 0 ; i < n ; i++){
            vector<bool>t(m,0);
            vis[i] = t;
        }  

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                
                //jumping down in a island
                if(grid[i][j] == '1' && vis[i][j] == 0 ){
                        dfs(grid,n,m,i,j,vis);
                        res++;
                }
            }
        }
        return res;
    }

};

