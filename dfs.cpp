#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{

    void dfs (vector<vector<int>> &adjlist, int node, vector<bool> &visited, vector<int> &result){
        
        result.push_back(node);
        visited[node] = true;

        for(int i = 0 ; i < adjlist[node].size() ; i++){
                int neighbour = adjlist[node][i];

                if(visited[neighbour] == false){
                    dfs(adjlist, neighbour, visited, result);
                }
        }

        return;
    }
};