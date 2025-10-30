#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsetsWithDup(int index, vector<int>& nums, vector<int> ds, int n){
    vector<vector<int>> powerSet;
    if(index==n){
        powerSet.push_back(ds);
        return powerSet;
    }
    ds.pop_back();
    int next_index=index+1;
    while(next_index<n && nums[next_index]==nums[index]){
        next_index++;
    }
    vector<vector<int>>left=subsetsWithDup(index+1,nums,ds,n);
    ds.push_back(nums[index]);
    vector<vector<int>> right=subsetsWithDup(index+1,nums,ds,n);
    powerSet=left;
    powerSet.insert(powerSet.end(),right.begin(),right.end());
    return powerSet;
}
int main(){
    vector<int> nums={1, 3, 3};
    int n=nums.size();
    vector<vector<int>>result=subsetsWithDup(0,nums,{},n);
    sort(nums.begin(),nums.end());
    for(const auto &subset : result){
        for(int i=0;i<subset.size();i++){
            cout<<subset[i];
            if(i+1<subset.size())cout<<" ,";
        }
    }
    return 0;
}