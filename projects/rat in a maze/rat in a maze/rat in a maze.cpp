

#include <iostream>
using namespace std;
int countt = 0;
bool ratinamaze(char maze[1001][1001], int sol[1001][1001], int i, int j, int rows, int col)
{
    //base case
    if (i == rows - 1 and j == col - 1)
    {
        sol[i][j] = 1;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        countt = countt + 1;
        return true;
    }

  




    //rec case

    sol[i][j] = 1;

    //forward
    if (j <= col - 2 and maze[i][j + 1] != 'X')
    {
        bool ans = ratinamaze(maze, sol, i, j + 1, rows, col);

        if (ans == true)
        {
            return true;
        }
    }

    //downward
    if (i <= rows - 2 and maze[i+1][j] != 'X')
    {
        bool ans = ratinamaze(maze, sol, i+1, j, rows, col);

        if (ans == true)
        {
            return true;
        }
    }
    sol[i][j] = 0;
    return false;

}

int main()
{
    
    int rows;
    int col;
    cin >> rows;
    cin>> col;
char maze[1001][1001];
    int sol[1001][1001] = { 0 };
    for (int l = 0; l < rows; l++)
    {
        for (int m = 0; m < col; m++)
        {
            cin >> maze[l][m];
        }
    }

    ratinamaze(maze, sol, 0, 0, rows, col);
    if (countt == 0)
    {
        cout << "-1";
    }
    return 0;
}

