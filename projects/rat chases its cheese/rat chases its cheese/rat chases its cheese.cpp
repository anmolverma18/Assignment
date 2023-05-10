

#include <iostream>
using namespace std;
int countt = 0;
bool ratchases(char maze[100][100], int sol[100][100],int visited [100][100],int i, int j, int rows, int col)
{
    //base case
    if (i == rows - 1 and j == col - 1)
    {
        sol[i][j] = 1;
        visited[i][j] = 1;

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
    visited[i][j] = 1;

    //forward
    if (visited[i][j+1]!=1 and j <= col - 2 and maze[i][j + 1] != 'X')
    {
        bool ans = ratchases(maze, sol,visited, i, j + 1, rows, col);

        if (ans == true)
        {
            return true;
        }
    }

    //downward
    if (visited[i+1][j]!=1 and i <= rows - 2 and maze[i + 1][j] != 'X')
    {
        bool ans = ratchases(maze, sol,visited, i + 1, j, rows, col);

        if (ans == true)
        {
            return true;
        }
    }

    //upward
    if (visited[i-1][j] != 1 and i>0 and maze[i-1][j] != 'X')
    {
        bool ans = ratchases(maze, sol, visited, i-1, j, rows, col);

        if (ans == true)
        {
            return true;
        }
    }

    //backward
    if (visited[i][j-1] != 1 and j > 0 and maze[i][j-1] != 'X')
    {
        bool ans = ratchases(maze, sol, visited, i , j-1, rows, col);

        if (ans == true)
        {
            return true;
        }
    }

    sol[i][j] = 0;
    visited[i][j] = 0;
    return false;

}

int main()
{

    int rows;
    int col;
    cin >> rows;
    cin >> col;
    char maze[100][100];
    int visited[100][100] = { 0 };
    int sol[100][100] = { 0 };
    for (int l = 0; l < rows; l++)
    {
        for (int m = 0; m < col; m++)
        {
            cin >> maze[l][m];
        }
    }

    ratchases(maze, sol,visited, 0, 0, rows, col);
    if (countt == 0)
    {
        cout << "-1";
    }
    return 0;
}

