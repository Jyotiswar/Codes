#include<iostream>
#include<vector>
using namespace std;
class Solution{
  public: 
        vector<vector<int>> adjlist(vector<vector<int>> & edges){
            int n = edges.size();
        
            vector<vector<int>>adj;

            for(int i = 0 ; i  < n ;i++){

              vector<int>edge = edges[i];

              int source = edge[0];
              int destination = edge[1];

              adj[source].push_back(destination);
              adj[destination].push_back(source);
            }

            return adj;
        }

};