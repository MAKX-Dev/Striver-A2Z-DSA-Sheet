#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums,int x){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>x){
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
    int x=9;
    vector<int> nums={3,5,8,15,19};
    int result=lowerBound(nums,x);
    cout<<"Upper Bound is: "<<result<<endl;

}