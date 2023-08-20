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

    cout << "Enter starting node: ";
    int start;
    cin >> start;

    vector<bool> visited(adjMatrix.at(0).size(), false);

    cout << "Enter width: ";
    int w;
    cin >> w;
    cout << "\nResult: ";
    bfs(start, visited, adjMatrix, w);

    return 0;
}