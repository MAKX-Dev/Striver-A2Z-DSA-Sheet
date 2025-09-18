#include<iostream>
#include<vector>
using namespace std;
void rearrangeArray(vector<int> &nums,int n){
    vector<int> ans(n,0);
    int posIndex=0;
    int negIndex=1;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            ans[negIndex]=nums[i];
            negIndex+=2;
        }
        else{
            ans[posIndex]=nums[i];
            posIndex+=2;

        }
    }
    nums=ans;
}
int main(){
    vector<int>nums={2, 4, 5, -1, -3, -4};
    int n=nums.size();
    rearrangeArray(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}