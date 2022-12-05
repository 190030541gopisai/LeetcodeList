// TC = O(N)
// SC = O(min(s.size(), numRows))
class Solution
{
    public:
        string convert(string s, int numRows)
        {
            
            bool down = true;
            int N = s.size(), window = 0;
            if(numRows <= 1 || N <= numRows) return s;

            string arr[numRows];

            for (int i = 0; i < N; i++)
            {
                arr[window] += s[i];
                if (down)
                {
                    if (window == (numRows - 1))
                    {
                        down = !down;	// up
                        window--;
                    }
                    else
                    {
                        window++;
                    }
                }
                else if (!down)
                {
                   	// up
                    if (window == 0)
                    {
                        down = !down;	// down
                        window++;
                    }
                    else
                    {
                        window--;
                    }
                }
            }

            string ans;

            for (string x: arr)
            {
                ans += x;
            }

            return ans;
        }
};