// SHREYASH NEGI
// UE203113
// CSE SECTION 2

// Iterative DFS 

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> &v, int a, int b)
{
    v.at(a).at(b) = 1;
    v.at(b).at(a) = 1;
}

void dfs(int start, vector<bool> &visited, vector<vector<int>> &adj, int d)
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

        for (int i = 0; i < adj.at(start).size(); i++)
        {
            if (adj.at(start).at(i) == 1 && (!visited.at(i)))
                dfs(i, visited, adj, d);
        }
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

    int maxDepth;
    cout << "Enter max depth: ";
    cin >> maxDepth;

    for (int d = 1; d < maxDepth; d++)
    {
        vector<bool> visited(v, false);
        cout << "Result for d = " << d << " : ";
        dfs(start, visited, adjMatrix, d);
        cout << endl;
    }

    return 0;
}