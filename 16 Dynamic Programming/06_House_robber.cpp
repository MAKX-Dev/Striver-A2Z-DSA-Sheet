#include<bits/stdc++.h>
using namespace std;
int nonAdjacent(vector<int>& nums){
    int n=nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    vector<int> dp(n);
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
int houseRobber(vector<int>& money){
    vector<int> temp1;  vector<int> temp2;
    int n=money.size();
    if(n==1){
        return money[0];
    }
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(money[i]);
        if(i!=n-1) temp2.push_back(money[i]);
    }
    return max(nonAdjacent(temp1),nonAdjacent(temp2));
    }
int main(){
    vector<int>money={1, 5, 2, 1, 6};
    int result=houseRobber(money);
    cout<<"maximum amount of possible money is: "<<result<<endl;
}