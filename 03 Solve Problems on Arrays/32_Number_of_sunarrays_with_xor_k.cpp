#include<iostream>
#include<map>
#include<vector>
using namespace std;
int subarraysWithXorK(vector<int> nums,int n,int k){
    int xr=0;
    int cnt=0;
    map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^nums[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;


    }
    return cnt;
}
int main(){
    vector<int> nums={4, 2, 2, 6, 4};
    int n=nums.size();
    int k=6;
    int result=subarraysWithXorK(nums,n,k);
    cout<<"total number of subarrays whose XOR equals to k are: "<<result<<endl;
    return 0;

    
}