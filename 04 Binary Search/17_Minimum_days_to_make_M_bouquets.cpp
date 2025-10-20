#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int> &nums,int day,int m,int k) {
    int n=nums.size(); 
    int cnt=0;
    int noOfB=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=day){
            cnt++;
        }
        else{
            noOfB+=(cnt/k);
            cnt=0;
        }
    }
    noOfB+=(cnt/k);
    return noOfB>=m;
}
int roseGarden(vector<int>nums,int k,int m) {
    int n=nums.size(); 
    long long totalRoses=(long long)m*k;
    if(n<totalRoses){
        return -1;
    }
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        mini=min(mini,nums[i]);
        maxi=max(maxi,nums[i]);
    }
    int low=mini,high=maxi;
    while(low<=high) {
        int mid=(low+high)/2;
        if(possible(nums,mid,m,k)){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int main()
{
    vector<int>nums={7, 7, 7, 7, 13, 11, 12, 7};
    int k=3;
    int m=2;
    int result=roseGarden(nums,k,m);
    if(result==-1)
        cout<<"We cannot make m bouquets"<<endl;
    else
        cout<<"We can make bouquets on day:  " <<result<<endl;
    return 0;
}
