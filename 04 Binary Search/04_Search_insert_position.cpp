#include<bits/stdc++.h>
using namespace std;
int insertPosition(vector<int> &nums,int x){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=x){
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
    int x=5;
    vector<int> nums={1, 3, 5, 6};
    int result=insertPosition(nums,x);
    cout<<"Insert Position is: "<<result<<endl;

}