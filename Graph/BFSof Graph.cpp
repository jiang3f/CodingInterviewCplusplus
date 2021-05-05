/
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
/*
*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS 
traversal of the graph starting from the 0th vertex, from left to right according to the graph. 
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
*/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BFSofGraph
{
    class Solution 
    {
    private:
        bool* isvisit;

    public:
        vector<int>bfsOfGraph(int V, vector<int> adj[]) 
        {
            // Code here
            isvisit = new bool[V];
            for (int i = 0; i < V; i++)
            {
                isvisit[i] = false;
            }

            vector<int> ans;

            queue<int> q;
            q.push(0);

            while (q.empty() == false)
            {
                int v = q.front();
                q.pop();

                vector<int>::iterator it;
                for (it = adj[v].begin(); it != adj[v].end(); it++)
                {
                    if (isvisit[*it] == false)
                    {
                        q.push(*it);
                    }
                }
            }


            return ans;
        }
    };
};

int BFSOfGraph_test()
{
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[10000];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        BFSofGraph::Solution obj;
        vector<int>ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
