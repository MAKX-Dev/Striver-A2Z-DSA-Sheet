#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums,int n){
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high){
       int mid=(low+high)/2;
       if(nums[low]<=nums[mid]){
        ans=min(ans,nums[low]);
        low=mid+1;
       }
       else{
        high=mid-1;
        ans=min(ans,nums[mid]);
       }
    }
    return ans;
}
int main(){
    vector<int> nums={4, 5, 6, 7, -7, 1, 2, 3};
    int n=nums.size();
    int result=findMin(nums,n);
    cout<<"minimum element in the array is: "<<result<<endl;

}