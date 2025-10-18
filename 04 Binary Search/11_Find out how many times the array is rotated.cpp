#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &nums,int n){
    int low=0;
    int high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(nums[mid]<=nums[high]){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> nums={4, 5, 1, 2};
    int n= nums.size();
    int result=findKRotation(nums,n);
    cout<<"number of rotations performed on the array is: "<<result<<endl;
}