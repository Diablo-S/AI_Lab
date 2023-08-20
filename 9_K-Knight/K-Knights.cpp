// SHREYASH NEGI
// UE203113

// K-Knights

#include <bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

int n, m, num;

vector<vector<int>> attack(vector<vector<int>> board, int i, int j)
{
    board[i][j] = 3;
    if (i + 2 <= m - 1)
    {
        if (j - 1 >= 0)
        {
            board[i + 2][j - 1] = 1;
        }
        if (j + 1 <= n - 1)
        {
            board[i + 2][j + 1] = 1;
        }
    }

    if (i + 1 <= m - 1)
    {

        if (j - 2 >= 0)
        {
            board[i + 1][j - 2] = 1;
        }
        if (j + 2 <= n - 1)
        {
            board[i + 1][j + 2] = 1;
        }
    }
    if (i - 2 >= 0)
    {
        if (j - 1 >= 0)
        {
            board[i - 2][j - 1] = 1;
        }
        if (j + 1 <= m - 1)
        {
            board[i - 2][j + 1] = 1;
        }
    }
    if (i - 1 >= 0)
    {

        if (j - 2 >= 0)
        {
            board[i - 1][j - 2] = 1;
        }
        if (j + 2 <= m - 1)
        {
            board[i - 1][j + 2] = 1;
        }
    }
    return board;
}

bool canPlace(vector<vector<int>> board, int i, int j)
{
    if (board[i][j] == 0)
    {
        return true;
    }
    return false;
}

void display(vector<vector<int>> board)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 3)
            {
                cout << "K ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}
void knight(int si, int sj, vector<vector<int>> board, int k)
{
    if (k == 0)
    {
        num++;
        display(board);
        cout << endl;
    }
    else
    {
        for (int i = si; i <= m - 1; i++)
        {
            for (int j = sj; j <= n - 1; j++)
            {

                if (canPlace(board, i, j))
                {

                    vector<vector<int>> temp;
                    temp = attack(board, i, j);
                    knight(i, j, temp, k - 1);
                }
            }
            sj = 0;
        }
    }
}

int main()
{
    cout << "Enter size of the board mxn : ";
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n, 0));

    cout << "Enter no. of Knights to be placed: ";
    int k;
    cin >> k;

    auto start = high_resolution_clock::now();
    knight(0, 0, v, k);
    auto stop = high_resolution_clock::now();

    cout << "The no. of possible boards is: " << num << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken is : " << duration.count() << " microseconds" << endl;

    return 0;
}