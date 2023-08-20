#include <bits/stdc++.h>
using namespace std;

int computer_move = -1;
 vector <int> magic={8,3,4,1,5,9,6,7,2};
void print_board(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 2)
        {
            cout << ".";
        }
        else if (v[i] == 3)
        {
            cout << "X";
        }
        else if (v[i] == 5)
        {
            cout << "O";
        }
        if ((i + 1) % 3 == 0)
        {
            cout << endl;
        }
        else
        {
            cout << "|";
        }
    }
    cout << endl;
}

int make2(vector<int> &v, int n)
{
    if (v[4] == 2)
    {
        computer_move = 4;
        return 4;
    }
    else
    {
        for (int i = 1; i <= 7; i += 2)
        {
            if (v[i] == 2)
            {
                computer_move = i;
                return i;
            }
        }
        return -1;
    }
}

void go(vector<int> &v, int n, int &turn)
{
    if (n < 0 || n > 8)
    {
        cout << "Out of bounds" << endl;
        return;
    }

    if (v[n] != 2)
    {
        cout << "invalid move" << endl;
        return;
    }
    v[n] = turn % 2 ? 5 : 3;
    turn++;
}

bool isempty(vector<int> &v, int i)
{
    if (v[i] == 2)
        return true;
    else
        return false;
}
int possible_winp(vector<int> &v, int n, char player)
{
    // int idx = -1;
    vector<int> placed;
        for (int i = 0; i < 9; i++)
            if (player == 'X' && v[i] == 3)
                placed.push_back(i);
            else if (player == 'O' && v[i] == 5)
                placed.push_back(i);

        for (int i = 0; i < placed.size(); i++)
            for (int j = i + 1; j < placed.size(); j++)
            {
                int temp = 15 - magic[placed[i]] - magic[placed[j]];
                if (temp >= 1 && temp <= 9)
                {
                    int idx = -1;
                    for (int k = 0; k < 9; k++)
                        if (temp == magic[k])
                        {
                            idx = k;
                            break;
                        }
                    if (v[idx] == 2)
                        return idx;
                }
            }
        return -1;
}

int findblank(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 2)
        {
            computer_move = i;
            return i;
        }
    }
    return -1;
}

void make_move(vector<int> &v, int &turn)
{
    int move = -1;
    int n = v.size();
    switch (turn)
    {
    case 0:
        computer_move = 0;
        go(v, 0, turn);
        break;
    case 1:
        if (isempty(v, 4))
        {
            computer_move = 4;
            go(v, 4, turn);
        }
        else
        {
            computer_move = 0;
            go(v, 0, turn);
        }
        break;
    case 2:
        if (isempty(v, 8))
        {
            computer_move = 8;
            go(v, 8, turn);
        }
        else
        {
            computer_move = 2;
            go(v, 2, turn);
        }
        break;
    case 3:
        move = possible_winp(v, n, 'X');
        if (move == -1)
            go(v, make2(v, n), turn);
        else
            go(v, move, turn);
        break;
    case 4:
        move = possible_winp(v, n, 'X');
        if (move != -1)
        {
            go(v, move, turn);
            break;
        }
        move = possible_winp(v, n, 'O');
        if (move != -1)
            go(v, move, turn);
        else if (isempty(v, 6))
        {
            go(v, 6, turn);
            computer_move = 6;
        }
        else
        {
            go(v, 2, turn);
            computer_move = 2;
        }
        break;
    case 5:
        move = possible_winp(v, n, 'O');
        if (move != -1)
        {
            go(v, move, turn);
            break;
        }
        move = possible_winp(v, n, 'X');
        if (move != -1)
        {
            go(v, move, turn);
            break;
        }
        move = make2(v, n);
        if (move != -1)
            go(v, move, turn);
        else
            go(v, findblank(v), turn);
        break;
    case 6:
    case 8:
        move = possible_winp(v, n, 'X');
        if (move != -1)
        {
            go(v, move, turn);
            break;
        }
        move = possible_winp(v, n, 'O');
        if (move != -1)
            go(v, move, turn);
        else
            go(v, findblank(v), turn);
        break;
    case 7:
        move = possible_winp(v, n, 'O');
        if (move != -1)
        {
            go(v, move, turn);
            break;
        }
        move = possible_winp(v, n, 'X');
        if (move != -1)
            go(v, move, turn);
        else
            go(v, findblank(v), turn);
        break;
    default:
        break;
    }
}
int checkwin(vector<int> &board)
{
    vector<int> placedX, placedO;
        for (int i = 0; i < 9; i++)
            if (board[i] == 3)
                placedX.push_back(i);
            else if (board[i] == 5)
                placedO.push_back(i);

        for (int i = 0; i < placedX.size(); i++)
            for (int j = i + 1; j < placedX.size(); j++)
                for (int k = j + 1; k < placedX.size(); k++)
                    if (magic[placedX[i]] + magic[placedX[j]] + magic[placedX[k]] == 15)
                        return 1;

        for (int i = 0; i < placedO.size(); i++)
            for (int j = i + 1; j < placedO.size(); j++)
                for (int k = j + 1; k < placedO.size(); k++)
                    if (magic[placedO[i]] + magic[placedO[j]] + magic[placedO[k]] == 15)
                        return 2;
        return 0;
}

void print_moves(vector<int> moves)
{
    for (int i = 0; i < moves.size(); i++)
        cout << moves[i] << " ";
    cout << endl;
}

void clearMove(vector<int> &v, int &i, int &turn)
{
    if (v[i] != 2)
    {
        v[i] = 2;
        turn--;
    }
}
int main()
{
    vector<int> board;
    board.resize(9, 2);
    int n = board.size();
    int blank = 2, X = 3, O = 5;
    cout << "Do you want to play (yes/no)" << endl;
    string choice;
    cin >> choice;
    int turn = 0;
    print_board(board, n);
    if (choice == "yes")
    {
        while (turn < 9)
        {
            if (turn % 2 == 0)
            {
                int move;
                cout << "enter your move" << endl;
                cin >> move;
                move--;
                go(board, move, turn);
            }
            else
            {
                make_move(board, turn);
            }
            print_board(board, n);
            int win = checkwin(board);
            if (win == 1)
            {
                cout << "You win!" << endl;
                break;
            }
            else if (win == 2)
            {
                cout << "Computer wins!" << endl;
                break;
            }
        }
    }
    else if (choice == "no")
    {
        while (turn < 9)
        {
            if (turn % 2 != 0)
            {
                int move;
                cout << "enter your move" << endl;
                cin >> move;
                move--;
                go(board, move, turn);
            }
            else
            {
                make_move(board, turn);
            }
            print_board(board, n);
            int win = checkwin(board);
            if (win == 2)
            {
                cout << "You win!" << endl;
                break;
            }
            else if (win == 1)
            {
                cout << "Computer wins!" << endl;
                break;
            }
        }
    }
}