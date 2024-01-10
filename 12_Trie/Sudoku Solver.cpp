#include <bits/stdc++.h>

bool check(int rw, int cl, vector<vector<int>> &sudoku, int num)
{

    int s = sudoku.size();

    for (int i = 0; i < s; i++)
    {
        if (sudoku[rw][i] == num || sudoku[i][cl] == num)
        {
            return false;
        }

        if (sudoku[3 * (rw / 3) + i / 3][3 * (cl / 3) + i % 3] == num)
        {
            return false;
        }
    }
    return true;
}

bool answer(vector<vector<int>> &sudoku)
{
    int s = sudoku[0].size();

    for (int rw = 0; rw < s; rw++)
    {
        for (int cl = 0; cl < s; cl++)
        {
            if (sudoku[rw][cl] == 0)
            {
                for (int num = 1; num < 10; num++)
                {
                    if (check(rw, cl, sudoku, num))
                    {
                        sudoku[rw][cl] = num;
                        bool nxtposible = answer(sudoku);

                        if (nxtposible)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[rw][cl] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    answer(sudoku);
}