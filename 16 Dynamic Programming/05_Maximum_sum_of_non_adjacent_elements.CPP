#include<bits/stdc++.h>
using namespace std;
int nonAdjacent(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    vector<int> dp(n);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int pick=nums[i]+dp[i-2];
        int not_pick=dp[i-1];
        dp[i]=max(pick,not_pick);
    }
    return dp[n-1];
}
int main(){
    vector<int> nums={1, 7, 16, 8};
    int result=nonAdjacent(nums);
    cout<<"maximum sum possible is: "<<result<<endl;
    return 0;
}