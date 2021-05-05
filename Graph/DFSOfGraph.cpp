//
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
/*
*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from 
the 0th vertex from left to right according to the graph..
*/
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace DFSOfGraph
{

    // it wasn't tested.

    class Solution {
    private:
        bool * isvisit;

    public:
        void dfsOfGraph_Sub(vector<int> &ans, int v, vector<int> adj[])
        {
            if (isvisit[v] == true) return;

            ans.push_back(v);

            vector<int>::iterator it;
            for (it = adj[v].begin(); it != adj[v].end(); it++)
            {
                dfsOfGraph_Sub(ans, *it, adj);
            }
        }

        vector<int>dfsOfGraph(int V, vector<int> adj[]) 
        {
            // Code here
            isvisit = new bool[V];
            for (int i = 0; i < V; i++)
            {
                isvisit[i] = false;
            }

            vector <int> ret;

            dfsOfGraph_Sub(ret, 0, adj);

            return ret;
        }
    };
};

int DFSOfGraph_Test()
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
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        DFSOfGraph::Solution obj;
        vector<int>ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}