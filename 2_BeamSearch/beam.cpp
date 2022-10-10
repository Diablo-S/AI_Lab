// SHREYASH NEGI
// UE203113
// CSE SECTION 2

// Beam Search

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>> &v, int a, int b)
{
    v.at(a).at(b) = 1;
    v.at(b).at(a) = 1;
}

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
    int v;
    int e;

    cout << "\nInput Graph\n"
         << endl;

    cout << "Enter no. of vertices: ";
    cin >> v;

    cout << "Enter no. of edges: ";
    cin >> e;

    vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++)
    {
        int from;
        int to;
        cout << "Enter edge " << i + 1 << " from: ";
        cin >> from;
        cout << "to: ";
        cin >> to;

        addEdge(adjMatrix, from, to);
    }

    cout << "Enter starting node: ";
    int start;
    cin >> start;
    
    vector<bool> visited(v, false);

    cout << "Enter width: ";
    int w;
    cin >> w;
    cout << "\nResult: ";
    bfs(start, visited, adjMatrix, w);

    return 0;
}