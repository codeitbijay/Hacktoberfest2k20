class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mins=1000000000, maxs=-1, maxsi=-1, minsi=-1;
        int diff=0;
        for(int i=0;i<prices.size();i++)
        {
            if(maxs<prices[i])
            {   maxs=prices[i];
                maxsi=i;
            }
            if(mins>prices[i])
            {   mins=prices[i];
                minsi=i;
                if(minsi>maxsi)
                {maxsi=minsi;maxs=prices[maxsi];}
            }
            diff=max(diff,maxs-mins);
        }
        return diff;
    }
};