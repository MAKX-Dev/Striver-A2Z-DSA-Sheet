#include<bits/stdc++.h>
using namespace std;
int calculateTotalHours(vector<int>& nums, int speed) {
    int totalH=0;
    for (int bananas : nums) {
        totalH+=(int)ceil((double)bananas/speed);
    }
    return totalH;
}
int minimumRateToEatBananas(vector<int>& nums, int h){
    int maxPile=*max_element(nums.begin(), nums.end());
    int low=1,high=maxPile;
    int ans=maxPile;
    while(low<=high){
        int mid=low+(high-low)/2;
        int totalH=calculateTotalHours(nums, mid);
        if(totalH<=h){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={7, 15, 6, 3};
    int h=8;
    int result=minimumRateToEatBananas(nums,h);
    cout<<"minimum number of bananas the monkey must eat per hour to finish all the bananas within h hours: "<<result<<endl;;
    return 0;
}