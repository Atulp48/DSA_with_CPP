// the problem is solved with the help of the dynamic programing and used memoazation method

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<int> &nums1, vector<int> &nums2, int ind, bool swapp)
    {

        int result = INT_MAX;

        if (ind == nums2.size())
        {
            return 0;
        }

        if (dp[ind][swapp] != -1)
        {
            return dp[ind][swapp];
        }

        int prev1 = nums1[ind - 1];
        int prev2 = nums2[ind - 1];

        if (swapp)
        {
            swap(prev1, prev2);
        }

        if (prev1 < nums1[ind] && prev2 < nums2[ind])
        {
            result = answer(nums1, nums2, ind + 1, 0);
        }

        if (prev2 < nums1[ind] && prev1 < nums2[ind])
        {
            int temp = 1 + answer(nums1, nums2, ind + 1, 1);
            result = min(result, temp);
        }
        return dp[ind][swapp] = result;
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        dp.resize(nums1.size(), vector<int>(2, -1));

        bool swapp = 0;
        return answer(nums1, nums2, 1, swapp);
    }
};

// the above problem is soolved with the help of the dynamic programing and used the tabulation method

class Solution
{

    vector<vector<int>> dp;

private:
    int answer(vector<int> &nums1, vector<int> &nums2)
    {
        int size = nums1.size();
        dp.resize(size + 1, vector<int>(2, 0));

        for (int ind = size - 1; ind >= 1; ind--)
        {

            for (int swapp = 1; swapp >= 0; swapp--)
            {

                int result = INT_MAX;

                int prev1 = nums1[ind - 1];
                int prev2 = nums2[ind - 1];

                if (swapp)
                {
                    swap(prev1, prev2);
                }

                if (prev1 < nums1[ind] && prev2 < nums2[ind])
                {
                    result = dp[ind + 1][0];
                }

                if (prev2 < nums1[ind] && prev1 < nums2[ind])
                {
                    int temp = 1 + dp[ind + 1][1];
                    result = min(result, temp);
                }
                dp[ind][swapp] = result;
            }
        }
        return dp[1][0];
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        return answer(nums1, nums2);
    }
};

// the above problem solved with the  help of the dynamic programing and  use the space  optimazation

class Solution
{

private:
    int answer(vector<int> &nums1, vector<int> &nums2)
    {
        int size = nums1.size();
        int swapped = 0;
        int noswapped = 0;
        int currswapped = 0;
        int currnoswapped = 0;

        for (int ind = size - 1; ind >= 1; ind--)
        {

            for (int swapp = 1; swapp >= 0; swapp--)
            {

                int result = INT_MAX;

                int prev1 = nums1[ind - 1];
                int prev2 = nums2[ind - 1];

                if (swapp)
                {
                    swap(prev1, prev2);
                }

                if (prev1 < nums1[ind] && prev2 < nums2[ind])
                {
                    result = noswapped;
                }

                if (prev2 < nums1[ind] && prev1 < nums2[ind])
                {
                    int temp = 1 + swapped;
                    result = min(result, temp);
                }

                if (swapp)
                {
                    currswapped = result;
                }
                else
                {
                    currnoswapped = result;
                }
            }
            swapped = currswapped;
            noswapped = currnoswapped;
        }
        return min(swapped, noswapped);
    }

public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        return answer(nums1, nums2);
    }
};