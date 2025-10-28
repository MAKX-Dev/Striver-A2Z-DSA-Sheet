#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>powerSet(vector<int> &nums,int n){
    vector<vector<int>> ans;
    int total=1<<n;
    for(int mask=0;mask<total;mask++){
        vector<int> subset;
        for(int j=0;j<n;j++){
            if((mask & (1<<j))!=0){
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}
int main(){
    vector<int> nums={1, 2, 3};
    int n=nums.size();
    vector<vector<int>>result=powerSet(nums,n);
    for(const auto &subset : result){
        for(int j=0;j<subset.size();j++){
            cout<<subset[j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}