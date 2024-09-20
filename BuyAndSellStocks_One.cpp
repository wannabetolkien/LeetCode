// Question : Best Time to Buy and Sell Stocks.

/*
You are given an array prices where prices[i] is the price of a given stock on the
ith day.You want to maximize your profit by choosing a single day to buy one stock and
choosing a different day in the future to sell that stock.Return the maximum profit you
can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

// Approach (Optimal) : Buy on the day when price is minimum and corresponding to that sell
//                      on the day where the profit is maximum.



/* Nabeel Akhter - Bismillah */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lint long long int
#define mod 1000000007

lint brute(vector<lint> &a){
    lint profit=0;
    for(int i=a.size()-1;i>=0;i--){
        lint m=INT_MAX;
        for(int j=i-1;j>=0;j--){
            m=min(m,a[j]);
        }
        profit=max(profit,a[i]-m);
    }

    return profit;
}

lint optimal(vector<lint> &a){
    lint profit=0;
    lint buyPrice=a[0];
    for(int i=1;i<a.size();i++){
        buyPrice=min(buyPrice,a[i]);
        profit=max(profit,buyPrice-a[i]);
    }

    return profit;
}



int main(){
    vector<int> a={-8,8,10,6,6,-4};
}