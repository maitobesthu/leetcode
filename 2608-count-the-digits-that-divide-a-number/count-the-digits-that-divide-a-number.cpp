class Solution
{
    public:
        int countDigits(int num)
        {
            int count = 0;
            int x = num;
            while (x > 0)
            {
                int d = x % 10;
                if (num % d == 0)
                {
                    count++;
                }
                x /= 10;
            }
            return count;
        }
};