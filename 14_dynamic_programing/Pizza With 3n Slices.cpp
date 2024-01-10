//  the  problem is solved  with the the help of the  dynamic programing  with the help of  top to down approach

class Solution
{

private:
    int answer(vector<int> &slices, int ind, int n, int end_ind, vector<vector<int>> &dp)
    {

        if (n == 0 || ind > end_ind)
        {
            return 0;
        }
        if (dp[ind][n] != -1)
        {
            return dp[ind][n];
        }

        int take = slices[ind] + answer(slices, ind + 2, n - 1, end_ind, dp);
        int not_take = answer(slices, ind + 1, n, end_ind, dp);
        dp[ind][n] = max(take, not_take);
        return dp[ind][n];
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int size = slices.size();
        vector<vector<int>> dp_1(size, vector<int>(size, -1));
        vector<vector<int>> dp_2(size, vector<int>(size, -1));
        int cond_1 = answer(slices, 0, size / 3, size - 2, dp_1);
        int cond_2 = answer(slices, 1, size / 3, size - 1, dp_2);
        return max(cond_1, cond_2);
    }
};

// the problem is solved with the help of the dynamic programing and used the tabulation method

class Solution
{

private:
    int answer(vector<int> &slices)
    {
        int size = slices.size();
        vector<vector<int>> dp_1(size + 2, vector<int>(size + 2, 0));
        vector<vector<int>> dp_2(size + 2, vector<int>(size + 2, 0));

        for (int ind = size - 2; ind >= 0; ind--)
        {
            for (int n = 1; n <= size / 3; n++)
            {

                int take = slices[ind] + dp_1[ind + 2][n - 1];
                int not_take = dp_1[ind + 1][n];
                dp_1[ind][n] = max(take, not_take);
            }
        }

        int cond_1 = dp_1[0][size / 3];

        for (int ind = size - 1; ind >= 1; ind--)
        {
            for (int n = 1; n <= size / 3; n++)
            {

                int take = slices[ind] + dp_2[ind + 2][n - 1];
                int not_take = dp_2[ind + 1][n];
                dp_2[ind][n] = max(take, not_take);
            }
        }
        int cond_2 = dp_2[1][size / 3];

        return max(cond_1, cond_2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {

        return answer(slices);
    }
};

// the problem is solved with the help of the dynamic programing and used the   space optmisation method

class Solution
{

private:
    int answer(vector<int> &slices)
    {
        int size = slices.size();
        vector<int> prev_1(size + 2, 0);
        vector<int> prev_2(size + 2, 0);

        vector<int> curr_1(size + 2, 0);
        vector<int> curr_2(size + 2, 0);

        vector<int> next_1(size + 2, 0);
        vector<int> next_2(size + 2, 0);

        for (int ind = size - 2; ind >= 0; ind--)
        {
            for (int n = 1; n <= size / 3; n++)
            {

                int take = slices[ind] + next_1[n - 1];
                int not_take = curr_1[n];
                prev_1[n] = max(take, not_take);
            }
            next_1 = curr_1;
            curr_1 = prev_1;
        }

        int cond_1 = curr_1[size / 3];

        for (int ind = size - 1; ind >= 1; ind--)
        {
            for (int n = 1; n <= size / 3; n++)
            {

                int take = slices[ind] + next_2[n - 1];
                int not_take = curr_2[n];
                prev_2[n] = max(take, not_take);
            }
            next_2 = curr_2;
            curr_2 = prev_2;
        }
        int cond_2 = curr_2[size / 3];

        return max(cond_1, cond_2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {

        return answer(slices);
    }
};