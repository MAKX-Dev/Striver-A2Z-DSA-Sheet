#include<bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int> nums,int k,int dist){
    int cntCows=1;
    int last=nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]-last>=dist){
            cntCows++;
            last=nums[i];
        }
        if(cntCows>=k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &nums,int k){
    sort(nums.begin(),nums.end());
    int low=0;
    int high=nums[nums.size()-1]-nums[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(nums,k,mid)==true){
            low=mid+1;
        }
        else high=mid-1;

    }
    return high;

}
int main(){
    vector<int> nums={0, 3, 4, 7, 10, 9};
    int k=4;
    int result=aggressiveCows(nums,k);
    cout<<"maximum possible minimum distance is: "<<result<<endl;
    return 0;

}