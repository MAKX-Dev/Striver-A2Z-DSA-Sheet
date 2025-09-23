#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums,int n,int target){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){ continue; }
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]){ continue; }
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j];
                sum+=nums[k]+nums[l];
                if(sum==target){
                   vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                   ans.push_back(temp);
                   k++;
                   l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    l--;
                }
            }
            while(k<l && nums[k]==nums[k-1]){
                k++;
            }
            while(k<l && nums[l]==nums[l+1]){
                l--;
            }

        }
    }
    return ans;
}
int main(){
    vector<int> nums={1, -2, 3, 5, 7, 9};
    int target=7;
    int n=nums.size();
    vector<vector<int>> result=fourSum(nums,n,target);
    cout<<"Required quadruplets [nums[i], nums[j], nums[k], nums[l]] are: ";
    for(auto it : result){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}