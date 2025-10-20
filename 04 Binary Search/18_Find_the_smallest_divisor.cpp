#include<bits/stdc++.h>
using namespace std;
int sumOfDiv(vector<int> nums,int limit,int mid){
    long long sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=(nums[i]+mid-1)/mid;
    }
    return sum;

}
 int smallestDivisor(vector<int> &nums, int limit){
    if(nums.size()>limit) return -1;
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if (sumOfDiv(nums,limit,mid)<=limit) {
            ans=mid;
            high=mid-1;
        }
    else{
        low=mid+1;
    }

       
    }
    return ans;
}
int main(){
    vector<int> nums={1, 2, 3, 4, 5};
    int limit=8;
    int result=smallestDivisor(nums,limit);
    cout<<"smallest positive integer divisor is: "<<result<<endl;
    return 0;

}
