#include<bits/stdc++.h>
using namespace std;
int countSubsequences(int index,int currentSum,vector<int>&nums,int k){
    if (index==nums.size()){
        if(currentSum==k){
            return 1; 
        }
        return 0;
    }
    int count_from_picking=countSubsequences(index+1,currentSum+nums[index],nums,k);
    int count_from_not_picking=countSubsequences(index+1,currentSum,nums,k);
    return count_from_picking + count_from_not_picking;
}
int main(){
    vector<int> nums={4, 9, 2, 5, 1};
    int k=10;
    int n=nums.size();
    int result=countSubsequences(0,0,nums,k);
    cout<<"Number of subsequences with sum "<<k<<" is: "<<result<<endl; 
    return 0;

}