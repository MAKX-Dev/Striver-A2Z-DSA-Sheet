#include<iostream>
#include<vector>
#include<map>
using namespace std;
int sunarraySum(vector<int> nums,int k){
    map<int,int> mpp;
    int preSum=0; int cnt=0;
    int n=nums.size();
    mpp[0]=1;
    for(int i=0;i<n;i++){
        preSum+=nums[i];
        int remove=preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;

}

    


int main(){
    vector<int> nums={3,1,2,4};
    int n=nums.size();
    int k=6;
    int cnt=sunarraySum(nums,k);
    cout<<cnt<<endl;
}