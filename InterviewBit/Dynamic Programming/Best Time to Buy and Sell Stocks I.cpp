int Solution::maxProfit(const vector<int> &A) {
    int maxprofit = 0;
    int minprice = INT_MAX;

    for(int i = 0; i < A.size(); i++)
    {
        minprice = min(minprice, A[i]);
        maxprofit = max(maxprofit, A[i] - minprice);
    }
    return maxprofit;
}
// finding max difference between 2 numbers;