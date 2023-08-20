#include <bits/stdc++.h>

using namespace std;
int board[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};

int poswin(char a)
{
    int j;
    if (a == 'x')
    {
        j = 3;
    }
    else if (a == 'o')
    {
        j = 5;
    }

    int magic[9] = {8, 3, 4, 1, 5, 9, 6, 7, 2};
    int inmag[9] = {3, 8, 1, 2, 4, 6, 7, 0, 5};
    int last = -1;
    for (int i = 0; i <= 9; i++)
    {
        if (i >= 8)
        {
            return -1;
        }
        else if (board[i] == j)
        {
            if (last == -1)
            {
                last = i;
                continue;
            }
            else
            {
                int sum = 14 - magic[i] - magic[last];
                last = i;

                if (board[inmag[sum]] == 2)
                {
                    return inmag[sum];
                }
            }
        }
    }

    return -1;
}

int check(char a)
{
    int j;
    if (a == 'x')
    {
        j = 27;
    }
    else if (a == 'o')
    {
        j = 125;
    }
    for (int i = 1; i <= 3; i++)
    {
        int k = 3 * i;
        if (board[k - 3] * board[k - 2] * board[k - 1] == j)
        {
            return j;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[i] * board[i + 3] * board[i + 6] == j)
        {
            return j;
        }
    }
    if (board[0] * board[4] * board[8] == j)
    {
        return j;
    }
    else if (board[2] * board[4] * board[6] == j)
    {
        return j;
    }
    else
    {
        return -1;
    }
}

int maket()
{
    if (board[4] == 2)
    {
        return 4;
    }
    else if (board[1] == 2)
    {
        return 1;
    }
    else if (board[3] == 2)
    {
        return 3;
    }
    else if (board[5] == 2)
    {
        return 5;
    }
    else if (board[7] == 2)
    {
        return 7;
    }
    else
    {
        return -1;
    }
}

void display()
{
    for (int i = 1; i <= 9; i++)
    {
        if (board[i - 1] == 2)
        {
            cout << "_ ";
        }
        else if (board[i - 1] == 3)
        {
            cout << "x ";
        }
        else if (board[i - 1] == 5)
        {
            cout << "o ";
        }

        if (i % 3 == 0)
        {
            cout << endl;
        }
    }
}

void go(int pos, int turn)
{
    if (turn % 2 == 0)
    {
        board[pos] = 5;
    }
    else
    {
        board[pos] = 3;
    }
}
void computer(int turn)
{
    switch (turn)
    {
    case 1:
        go(0, 1);
        break;
    case 2:
        if (board[4] == 2)
        {
            go(4, 2);
        }
        else
        {
            go(0, 2);
        }
        break;
    case 3:
        if (board[8] == 2)
        {
            go(8, 3);
        }
        else
        {
            go(2, 3);
        }
        break;
    case 4:
        if (poswin('x') != -1)
        {
            go(poswin('x'), 4);
        }
        else
        {
            go(maket(), 4);
        }
        break;
    case 5:
        if (poswin('x') != -1)
        {
            go(poswin('x'), 5);
        }
        else if (poswin('o') != -1)
        {
            go(poswin('o'), 5);
        }
        else if (board[6] == 2)
        {
            go(6, 5);
        }
        else
        {
            go(2, 5);
        }
        break;
    case 6:
        if (poswin('o') != -1)
        {
            go(poswin('o'), 6);
        }
        else if (poswin('x') != -1)
        {
            go(poswin('x'), 6);
        }
        else
        {
            go(maket(), 6);
        }
        break;
    case 7:
        if (poswin('x') != -1)
        {
            go(poswin('x'), 7);
        }
        else if (poswin('o') != -1)
        {
            go(poswin('o'), 7);
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 2)
                {
                    go(i, 7);
                    break;
                }
            }
        }
        break;
    case 8:
        if (poswin('o') != -1)
        {
            go(poswin('o'), 8);
        }
        else if (poswin('x') != -1)
        {
            go(poswin('x'), 8);
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 2)
                {
                    go(i, 8);
                    break;
                }
            }
        }
        break;
    case 9:
        if (poswin('x') != -1)
        {
            go(poswin('x'), 9);
        }
        else if (poswin('o') != -1)
        {
            go(poswin('o'), 9);
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i] == 2)
                {
                    go(i, 9);
                    break;
                }
            }
        }
        break;
    }
}
void usert(int turn)
{
    int u;
    cout << "Enter the sqaure: " << endl;
    cin >> u;
    cout << endl;
    if (board[u - 1] != 2)
    {
        cout << "Invalid square";
        usert(turn);
    }
    else
    {
        go(u - 1, turn);
    }
}
int main()
{
    char a = 'x';
    int turn = 1;
    int ch;
    cout << "If you want to start first press 1 else press 0" << endl;
    cin >> ch;
    if (ch == 0)
    {
        while (turn <= 9 && check('x') == -1 && check('o') == -1)
        {
            computer(turn);
            display();
            if (check('x') != -1)
            {
                break;
            }
            cout << endl;
            turn++;
            if (turn >= 9)
            {
                break;
            }
            cout << endl;
            if (turn >= 9)
            {
                break;
            }
            usert(turn);
            turn++;

            display();
            cout << endl;
        }
    }
    else if (ch == 1)
    {
        while (turn <= 9 && check('x') == -1 && check('o') == -1)
        {
            usert(turn);
            display();
            if (check('x') != -1)
            {
                break;
            }
            cout << endl;
            turn++;
            cout << endl;
            computer(turn);
            if (check('o') != -1)
            {
                break;
            }
            turn++;
            display();
            cout << endl;
        }
    }
    else
    {
        cout << "Invalid Choice";
        return 0;
    }

    if (check('o') == 125)
    {
        if (ch == 0)
        {
            cout << "User Wins!!!" << endl;
        }
        else
        {
            cout << "Computer Wins!!!" << endl;
        }
    }
    else if (check('x') == 27)
    {
        if (ch == 0)
        {
            cout << "Computer Wins!!!" << endl;
        }
        else
        {
            cout << "User Wins!!!" << endl;
        }
    }
    else
    {
        cout << "Draw!!!" << endl;
    }

    return 0;
}