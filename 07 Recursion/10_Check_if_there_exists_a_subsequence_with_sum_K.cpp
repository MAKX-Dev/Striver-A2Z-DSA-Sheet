#include<bits/stdc++.h>
using namespace std;
bool countSubsequences(int index,int currentSum,vector<int>&nums,int k){
    if(index==nums.size()){
        if(currentSum==k){
            return true;
        }
        return false;
    } 
    bool count_from_picking=countSubsequences(index+1,currentSum+nums[index],nums,k);
    bool count_from_not_picking=countSubsequences(index+1,currentSum,nums,k);
    return count_from_picking || count_from_not_picking;
}
int main(){
    vector<int> nums={1, 2, 3, 4, 5};
    int k=8;
    int n=nums.size();
    bool result=countSubsequences(0,0,nums,k);
    if(result){
        cout<<"YES,there exist such subsequences"<<endl;
    }
    else{
        cout<<"NO,there doesn't exist such subsequences"<<endl;
    }
    return 0;
}