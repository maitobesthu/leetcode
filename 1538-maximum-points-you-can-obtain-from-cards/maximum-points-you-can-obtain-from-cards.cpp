class Solution
{
    public:
        int maxScore(vector<int> &cardPoints, int k)
        {
            int n = cardPoints.size();
            vector<int> front(k + 1, 0), back(k + 1, 0);
            for (int i = 1; i <= k; i++)
            {
                front[i] = front[i - 1] + cardPoints[i - 1];
            }
            for (int i = 1; i <= k; i++)
            {
                back[i] = back[i - 1] + cardPoints[n - i];
            }
            int ans = 0;
            for (int i = 0; i <= k; i++)
            {
                ans = max(ans,(front[i]+back[k-i]));
            }
            return ans;
        }
};