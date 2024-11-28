// leetcode 121 : Best time to buy and sell stock

#include <iostream>
#include <vector>
using namespace std;

int BuyandSell(vector<int> &prices)
{
    int MaxProfit = 0;       // 4, 4, 5, 5
    int bestBuy = prices[0]; // 7 , 1, 1, 1, 1, 1

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > bestBuy) // 1 > 7 (false) , 5 > 1 (true) -> (0,4) = 4, 3 > 1 (true) -> (4,2) = 4, 6 > 1 (true) -> (4,5) = 5, 4 > 1 (true) -> (5,3) = 5
        {
            MaxProfit = max(MaxProfit, prices[i] - bestBuy);
        }

        bestBuy = min(bestBuy, prices[i]); // (0,1) = 1, (1,5) = 1, (1,3) = 1, (1, 6) = 1, (1,4) = 1
    }
    cout << "Best Buy = " << bestBuy << endl;
    return MaxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit = " << BuyandSell(prices) << endl;
    return 0;
}