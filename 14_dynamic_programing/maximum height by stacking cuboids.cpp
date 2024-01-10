class Solution
{
private:
    bool check(vector<int> base_box, vector<int> new_box)
    {
        if (new_box[0] <= base_box[0] && new_box[1] <= base_box[1] && new_box[2] <= base_box[2])
            return true;
        else
            return false;
    }

    int longestSubsequence(int n, vector<vector<int>> &a)
    {
        vector<int> curr_row(n + 1, 0);
        vector<int> next_row(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(a[curr], a[prev]))
                    include = a[curr][2] + next_row[curr + 1];

                int exclude = next_row[prev + 1];
                curr_row[prev + 1] = max(include, exclude);
            }
            next_row = curr_row;
        }
        return next_row[0];
    }

public:
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &i : cuboids)
        {
            sort(i.begin(), i.end());
        }

        sort(cuboids.begin(), cuboids.end());
        return longestSubsequence(cuboids.size(), cuboids);
    }
};