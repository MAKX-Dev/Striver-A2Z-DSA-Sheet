#include<bits/stdc++.h>
using namespace std;
int search(vector<int> nums,int n,int k){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==k){
            return mid;
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
    return -1;

}
int main(){
    vector<int> nums={4, 5, 6, 7, 0, 1, 2};
    int k=5;
    int  n=nums.size();
    int result=search(nums,n,k);
    cout<<"index at which k is present is: "<<result<<endl;


}