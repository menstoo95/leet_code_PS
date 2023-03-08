class Solution {
public:
    bool find_k(long long k, vector<int> piles, int h)
    {
        long long res = 0;

        for (double p : piles)
            res += ceil(p / k);

        return (res <= h);
    }

    int minEatingSpeed(vector<int> piles, int h)
    {
        long long l = 1, r = 1e9;

        while (l < r)
        {
            long long mid = (l + r) / 2;

            if (find_k(mid, piles, h))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};