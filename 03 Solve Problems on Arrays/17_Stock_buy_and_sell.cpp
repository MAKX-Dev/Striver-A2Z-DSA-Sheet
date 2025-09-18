#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int stockBuySell(vector<int> &prices,int n){
    int maxProfit=0;
    int mini=prices[0];
    for(int i=0;i<n;i++){
        int cost=prices[i]-mini;
        maxProfit=max(maxProfit,cost);
        mini=min(mini,prices[i]);
          
    }
    return maxProfit;

}
int main(){
    vector<int> prices={3, 8, 1, 4, 6, 2};
    int n=prices.size();
    int result=stockBuySell(prices,n);
    cout<<"maximum profit achievable by buying and selling the stock at most once: "<<result<<endl;



}