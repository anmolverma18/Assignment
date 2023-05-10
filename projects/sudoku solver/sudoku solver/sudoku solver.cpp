

#include <iostream>
using namespace std;
int countt = 0;
bool check(int mat[9][9], int i, int j, int n,int num)
{
    //vertical
    for (int k = 0; k < n; k++)
    {
        if (mat[k][j] == num)
        {
            return false;
        }
    }

    //horizontal
    for (int m = 0; m < n; m++)
    {
        if (mat[i][m] == num)
        {
            return false;
        }
    }

    //3x3 matrix

    int sn = sqrt(n);
    int si = (i / sn) * sn;
    int sj = (j / sn) * sn;

    for (int i = si; i < si + sn; i++)
    {
        for (int j = sj; j < sj + sn; j++)
        {
            if (mat[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}


bool sudokusolver(int mat[9][9],int i,int j,int n)
{
    //base case
    
    if (i == n)
    {
        for (int l = 0; l < n; l++)
        {
            for (int m = 0; m < n; m++)
            {
                cout << mat[l][m] << " ";
            }
            cout<<endl;
        }
        return true;
    }
    



    //rec case
    if (j == n)
    {
       return  sudokusolver(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
      return  sudokusolver(mat, i, j + 1, n);

    }

    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (check(mat, i, j, n, num))
            {
                mat[i][j] = num;

                bool ans = sudokusolver(mat, i, j + 1, n);
                if (ans == true)

                {
                    return true;
                }
            }
            mat[i][j] = 0;
        }
    }
  
   
    return false;

}

int main()
{
    int n;
    int mat[9][9];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << endl;
    sudokusolver(mat, 0, 0, n);
  
    return 0;
}

