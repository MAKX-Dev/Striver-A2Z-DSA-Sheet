#include<bits/stdc++.h>
using namespace std;
void func(int ind,int sum,vector<int> &nums,int n,vector<int>&sumSubSet){
    if(ind==n){
        sumSubSet.push_back(sum);
        return;
    }
    func(ind+1,sum+nums[ind],nums,n,sumSubSet);
    func(ind+1,sum,nums,n,sumSubSet);
}
vector<int> subSetSum(vector<int>&nums,int n){
    vector<int>sumSubSet;
    func(0,0,nums,n,sumSubSet);
    sort(sumSubSet.begin(),sumSubSet.end());
    return sumSubSet;
}
int main(){
    vector<int> nums={5, 2, 1};
    int n=nums.size();
    vector<int>result=subSetSum(nums,n);
    cout<<" ";
    for(int i=0;i<result.size();i++){
        if(i)cout<< " ";
        cout<<result[i];
    }
    cout<<endl;

}