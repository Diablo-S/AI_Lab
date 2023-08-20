// SHREYASH NEGI
// UE203113
// CSE SECTION 2

// Beam Search

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<bool> &visited, vector<vector<int>> &adj, int w)
{
    queue<int> open;
    queue<int> closed;

    open.push(start);
    visited.at(start) = true;

    while (!open.empty())
    {
        int temp;
        temp = open.front();
        open.pop();
        w++;
        closed.push(temp);

        for (int i = 0; i < adj.at(temp).size(); i++)
        {
            if (adj.at(temp).at(i) == 1 && (!visited.at(i)) && w != 1)
            {
                open.push(i);
                visited.at(i) = true;
                w--;
            }
        }
    }

    while (!closed.empty())
    {
        cout << closed.front() << " ";
        closed.pop();
    }
}

int main()
{
    vector<vector<int>> adjMatrix;

    // Sample 1
    // 10 Node graph

    adjMatrix = {{0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
                 {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                 {1, 1, 0, 0, 1, 0, 0, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
                 {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
                 {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                 {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                 {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};

    // Sample 2
    // 12 Node graph

    // adjMatrix = {{0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //              {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    //              {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    //              {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    //              {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    //              {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    //              {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //              {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    //              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    //              {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    //              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    //              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};

    cout << "\nEnter starting node: ";
    int start;
    cin >> start;

    for (int w = 1; w < 4; w++)
    {
        vector<bool> visited(adjMatrix.at(0).size(), false);
        cout << "\nResult when w = " << w << " : ";
        bfs(start, visited, adjMatrix, w);
    }
    
    return 0;
}