#include <bits/stdc++.h>
using namespace std;
char board[9][9];
bool isSafe(int x, int y, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == c)
        {
            return false;
        }
        if (board[i][y] == c)
        {
            return false;
        }
    }
    int topRow = x / 3  *3, topCol = y / 3  *3;
    for (int i = topRow; i < topRow + 3; i++)
    {
        for (int j = topCol; j < topCol + 3; j++)
        {
            if (board[i][j] == c)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve(int x, int y)
{
    for (char c = '1'; c <= '9'; c++)
    {
        if (isSafe(x, y, c))
        {
            board[x][y] = c;
            bool flag = false;
            for (int i = y + 1; i < 9; i++)
            {
                if (board[x][i] == '0')
                {
                    flag = true;
                    if (solve(x, i))
                    {
                        return true;
                    }
                    board[x][i] = '0';
                    break;
                }
            }
            if (!flag)
            {
                for (int i = x + 1; i < 9; i++)
                {
                    for (int j = 0; j < 9; j++)
                    {
                        if (board[i][j] == '0')
                        {
                            flag = true;
                            if (solve(i, j))
                            {
                                return true;
                            }
                            board[i][j] = '0';
                            break;
                        }
                    }
                    if (flag)
                    {
                        break;
                    }
                }
                if (!flag)
                {
                    for (int i = 0; i < 9; i++)
                    {
                        for (int j = 0; j < 9; j++)
                        {
                            cout << board[i][j] << " ";
                        }
                        cout << "\n";
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    int x = -1, y;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '0')
            {
                x = i, y = j;
                break;
            }
        }
        if (x != -1)
        {
            break;
        }
    }
    if (!solve(x, y))
    {
        cout << "NO solutions!";
    }
    
}
// 0 0 3 0 0 0 0 7 0
// 0 0 0 9 0 0 4 0 0
// 5 0 0 6 0 0 0 0 0
// 0 0 0 0 7 0 0 2 3
// 9 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 8 0
// 0 0 0 5 0 1 6 0 0
// 0 8 0 0 2 0 0 0 0
// 0 0 0 0 0 0 9 0 0