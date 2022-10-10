// SHREYASH NEGI
// UE203113
// CSE SECTION 2

// DFS/BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>> &v, int a, int b)
{
    v.at(a).at(b) = 1;
    v.at(b).at(a) = 1;
}

void dfs(int start, vector<bool> &visited, vector<vector<int>> &adj)
{
    cout << start << " ";

    visited.at(start) = true;

    for (int i = 0; i < adj.at(start).size(); i++)
    {
        if (adj.at(start).at(i) == 1 && (!visited.at(i)))
            dfs(i, visited, adj);
    }
}

void bfs(int start, vector<bool> &visited, vector<vector<int>> &adj)
{
    queue<int> open;
    queue<int> closed;

    open.push(start);
    visited.at(start) = true;

    while(!open.empty())
    {
        int temp;
        temp = open.front();
        open.pop();
        closed.push(temp);

        for(int i = 0; i < adj.at(temp).size(); i++)
        {
            if (adj.at(temp).at(i) == 1 && (!visited.at(i)))
            {
                open.push(i);
                visited.at(i) = true;
            }
        }
    }

    while(!closed.empty())
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

    cout << "\nWhich search do you want to perform ?" << endl;
    cout << "1. Depth First Search (DFS)" << endl;
    cout << "2. Breadth First Search (BFS)" << endl;

    cout << "\nEnter choice: ";
    int choice;
    cin >> choice;

    vector<bool> visited(v, false);

    switch (choice)
    {
    case 1:
        cout << "\nResult: ";
        dfs(start, visited, adjMatrix);
        break;
    case 2:
        cout << "\nResult: ";
        bfs(start, visited, adjMatrix);
        break;
    default:
        cout << "Invalid choice";
        break;
    }

    return 0;
}