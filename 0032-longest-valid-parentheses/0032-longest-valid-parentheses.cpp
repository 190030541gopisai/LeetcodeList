//  TC = O(N^2)
//  SC = O(1)
class Solution
{
    public:
        int longestValidParentheses(string s)
        {
            int n = s.length();
            int ans = 0, countOpen = 0, countClose = 0;

            for (int i = 0; i < n; i++)
            {
                countOpen = 0;
                countClose = 0;

                for (int j = i; j < n; j++)
                {
                    if (s[j] == '(')
                    {
                        countOpen++;
                    }
                    else
                    {
                        countClose++;
                    }

                    int diff = countOpen - countClose;
                    /*
                    diff < 0 
                    means that there are too many right parentheses. At this time, no matter what is behind it, it                       must be an illegal string, so the loop can be ended early
                    */
                    if (diff < 0)
                    {
                        break;
                    }

                   	// diff == 0 means we have both equal open and equal close
                    if (diff == 0)
                    {
                        ans = max(ans, j - i + 1);
                    }
                }
            }

            return ans;
        }
};