class Solution {
public:

    int diameter;

    int dfs(int node, int parent, vector<vector<int>>& G)
    {
        int longest = 0;
        int sec_longest = 0;

        for(auto child : G[node])
        {
            if(child == parent)
                continue;

            int h = dfs(child, node, G) + 1;

            if(h > longest)
            {
                sec_longest = longest;
                longest = h;
            }
            else if(h > sec_longest)
            {
                sec_longest = h;
            }
        }

        // V-shaped path through this node
        diameter = max(diameter, longest + sec_longest);

        // Return longest downward path
        return longest;
    }


    int getDiameter(vector<vector<int>>& G)
    {
        diameter = 0;

        // LeetCode nodes start from 0
        dfs(0, -1, G);

        return diameter;
    }


    int minimumDiameterAfterMerge(
        vector<vector<int>>& edges1,
        vector<vector<int>>& edges2)
    {
        // Number of nodes
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build first tree
        vector<vector<int>> G1(n);

        for(auto edge : edges1)
        {
            int u = edge[0];
            int v = edge[1];

            G1[u].push_back(v);
            G1[v].push_back(u);
        }

        // Build second tree
        vector<vector<int>> G2(m);

        for(auto edge : edges2)
        {
            int u = edge[0];
            int v = edge[1];

            G2[u].push_back(v);
            G2[v].push_back(u);
        }

        // Find diameters
        int d1 = getDiameter(G1);
        int d2 = getDiameter(G2);

        // Find radius of both trees
        int r1 = (d1 + 1) / 2;
        int r2 = (d2 + 1) / 2;

        // Longest path crossing the new edge
        int mergedPath = r1 + 1 + r2;

        // Final answer
        return max({d1, d2, mergedPath});
    }
};