#include<bits/stdc++.h>
using namespace std;
bool search(vector<int> nums,int n,int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==k){
            return true;
        }
        if(nums[low]=nums[high] && nums[mid]==nums[high]){
            low=low+1;
            high=high+1;
            continue;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=k && k<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<=k && k<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;

            }
        }

    }
    return false;

}
int main(){
    vector<int> nums={2,5,6,0,0,1,2};
    int k=0;
    int  n=nums.size();
    bool result=search(nums,n,k);
    cout<<result<<endl;

    // 1=TRUE
    // 0=FALSE


}