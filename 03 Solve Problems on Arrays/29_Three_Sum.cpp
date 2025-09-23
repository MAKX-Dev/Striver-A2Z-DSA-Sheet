#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums,int n) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
             if(sum<0){
                j++;
             }
             else if(sum>0){
                k--;
             }
             else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
             }
        }
        while(j<k && nums[j]==nums[j-1]){
            j++;
        }
        while(nums[k]==nums[k+1]){
            k--;
        }
       
    }
    return ans;


}
int main(){
    vector<int> nums={2, -2, 0, 3, -3, 5};
    int n=nums.size();
    vector<vector<int>> result=threeSum(nums,n);
    cout<<"Required Triplets are: "<<endl;
    for(auto it : result){
        for(int num : it){
            cout<<num<< " ";
        }
        cout<<endl;
    }

}