// SHREYASH NEGI
// UE203113
// CSE SECTION 2

// Iterative Deepening Beam Search
// w fixed

#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<bool> &visited, vector<vector<int>> &adj, int d, int w)
{
    if (d == 0)
    {
        return;
    }
    else
    {
        cout << start << " ";
        d--;

        visited.at(start) = true;
        
        int count = 0;

        for (int i = 0; i < adj.at(start).size(); i++)
        {
            if (adj.at(start).at(i) == 1 && (!visited.at(i)) && count < w)
            {
                count++;
                dfs(i, visited, adj, d, w);
            }
        }
    }
}

int main()
{

    vector<vector<int>> adjMatrix;

    // Sample graph
    // 13 Node graph

    //             0
    //           / | \
    //         1   2   3
    //       / | \ | \ /\
    //     4   5  6---7 8
    //    / \ /  / | / / \
    //   9    10----11    12

    adjMatrix = {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                 {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                 {0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                 {0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                 {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                 {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};

    cout << "Enter starting node: ";
    int start;
    cin >> start;

    int maxDepth{4};

    for (int w = 1; w < 4; w++)
    {
        cout << endl;
        cout << "For w = " << w << endl;
        for (int d = 1; d < maxDepth; d++)
        {
            vector<bool> visited(adjMatrix.at(0).size(), false);
            cout << "Result for d = " << d << " : ";
            dfs(start, visited, adjMatrix, d, w);
            cout << endl;
        }
    }

    return 0;
}