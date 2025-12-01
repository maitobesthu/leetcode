class Solution
{
    public:
        long long maxRunTime(int n, vector<int> &batteries)
        {
            long long sum = 0;
            for (int x: batteries) sum += x;

            long long low = 0;
            long long high = sum / n;	// max possible time

            auto canRun =[& ](long long T)->bool
            {
                long long total = 0;
                for (int x: batteries)
                {
                    total += min((long long) x, T);
                    if (total >= T *n) return true;	// early stop
                }
                return total >= T * n;
            };

            long long ans = 0;
            while (low <= high)
            {
                long long mid = low + (high - low) / 2;
                if (canRun(mid))
                {
                    ans = mid;
                    low = mid + 1;	// try bigger time
                }
                else
                {
                    high = mid - 1;	// try smaller time
                }
            }
            return ans;
        }
};