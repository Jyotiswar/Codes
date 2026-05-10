#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class solution{

    vector<int> bfs (vector<vector<int>>& adj){

        int n = adj.size();
        vector<int>result;
        vector<int>visited(n,false);
        queue<int>q;

        q.push(0);
        visited[0] = true;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            result.push_back(node);

            for(int i = 0 ; i < adj[node].size();i++){

                    int neighbour = adj[node][i];

                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }

            }


        }
        return result;

    }

};