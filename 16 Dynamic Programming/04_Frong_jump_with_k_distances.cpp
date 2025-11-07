#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>  &heights,int k,vector<int> &memo){
    if(heights.empty()){
        return 0;
    }
    if(ind==0) return 0;
    if(memo[ind]!=-1){
        return memo[ind];
    }
    int minimumCost=INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump=f(ind-j,heights,k,memo)+abs(heights[ind]-heights[ind-j]);
            minimumCost=min(jump,minimumCost);
        }
    }
    memo[ind]=minimumCost;
    return minimumCost;
}
int main(){
    vector<int> heights={15, 4, 1, 14, 15};
    int n=heights.size();
    vector<int> memo(n-1);
    int k=3;
    int ind=n-1;
    int result=f(n-1,heights,k,memo);
    cout<<result<<endl;
    return 0; 
}