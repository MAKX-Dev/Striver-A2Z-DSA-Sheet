#include<bits/stdc++.h>
using namespace std;
int nonAdjacent(vector<int>& nums) {
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    int prev2=nums[0];
    int prev1=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int pick=nums[i]+prev2;
        int not_pick=prev1;
        int curr=max(pick,not_pick);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    vector<int> nums={1, 7, 16, 8};
    int result=nonAdjacent(nums);
    cout<<"maximum sum possible is: "<<result<<endl;
    return 0;
}