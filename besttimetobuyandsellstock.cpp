class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0]; 
        int max = prices[0];
        int profit = max-min;
        
        for (int i=0; i<prices.size(); i++){
            int newProfit = prices[i] - min;
            if (newProfit > profit) {
                profit = newProfit;
            }
            else if (prices[i] < min) {
                min = prices[i];
            }
        }
        return profit;
        
    }
};
