#include<bits/stdc++.h>
using namespace std;
pair<int,int> getFloorAndCeil(vector<int> &nums,int x){
    vector<int> result;
    int n=nums.size();
    int ans=-1;
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]<=x){
            ans=nums[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    
    int lowerBound=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
   
    return {ans,nums[lowerBound]};
}
int main(){
    vector<int> nums={3, 4, 4, 7, 8, 10};
    int x=5;
     pair<int, int> solution=getFloorAndCeil(nums,x);
    cout<<"For x = "<<x<<endl;
    cout<<"Floor: "<<solution.first<<endl;  
    cout<<"Ceil: "<<solution.second<<endl; 
    
    return 0;
}