#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&nums,int mid){
    int student=1;
    int pagesStudent=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid){
            return INT_MAX;
        }
        if(pagesStudent+nums[i]<=mid){
            pagesStudent+=nums[i];
        }
        else{
            student++;
            pagesStudent=nums[i];
        }
    }
    return student;
}
int sumOfelements(vector<int>&nums){
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
    }
    return sum;
}
int findPages(vector<int> &nums,int m){
    int low=*max_element(nums.begin(), nums.end());
    int high=sumOfelements(nums);
    while(low<=high){
        int mid=low+(high-low)/2;
        int numberOfStudents=func(nums,mid);
        if(numberOfStudents>m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
        
    return low;
    }
int main(){
    vector<int> nums={12, 34, 67, 90};
    int m=2;
    int result=findPages(nums,m);
    cout<<result<<endl;
    return 0;
}
