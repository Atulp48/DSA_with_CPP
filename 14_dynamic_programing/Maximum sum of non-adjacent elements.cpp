#include <bits/stdc++.h>

int answer(int size, vector<int> &nums, vector<int> &store)
{
    if (size == 0)
    {
        return nums[0];
    }

    if (size < 0)
    {
        return 0;
    }

    if (store[size] != -1)
    {
        return store[size];
    }

    int cal = answer(size - 2, nums, store) + nums[size];
    int notcal = answer(size - 1, nums, store);

    store[size] = max(cal, notcal);
    return store[size];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int size = nums.size();
    vector<int> store(size + 1, -1);
    return answer(size - 1, nums, store);
}

// we use the tabulation method for solving the  above problem and the following code is run successfully on code studio

#include <bits/stdc++.h>

int answer(int size, vector<int> &nums)
{

    vector<int> store(size, 0);

    store[0] = nums[0];

    for (int i = 1; i < size; i++)
    {

        int cal = store[i - 2] + nums[i];
        int notcal = store[i - 1];
        store[i] = max(cal, notcal);
    }

    return store[size - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{

    int size = nums.size();
    return answer(size, nums);
}

//

#include <bits/stdc++.h>

int answer(int size, vector<int> &nums)
{
    int val1, val2;

    val1 = nums[0];
    val2 = 0;

    for (int i = 1; i < size; i++)
    {
        int val;
        int cal = val2 + nums[i];
        int notcal = val1;
        val = max(cal, notcal);
        val2 = val1;
        val1 = val;
    }

    return val1;
}

int maximumNonAdjacentSum(vector<int> &nums)
{

    int size = nums.size();
    return answer(size, nums);
}
