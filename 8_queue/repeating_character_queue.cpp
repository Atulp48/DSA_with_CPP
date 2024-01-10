
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        queue<int> Q;
        string STR = "";
        unordered_map<char, int> MP;

        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];

            MP[ch]++;

            Q.push(ch);

            while (!Q.empty())
            {
                if (MP[Q.front()] > 1)
                {
                    Q.pop();
                }
                else
                {
                    STR.push_back(Q.front());
                    break;
                }
            }

            if (Q.empty())
            {
                STR.push_back('#');
            }
        }

        return STR;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}
