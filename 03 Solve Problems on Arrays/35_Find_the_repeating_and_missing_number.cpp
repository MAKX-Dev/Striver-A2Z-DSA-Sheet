#include<iostream>
#include<vector>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> nums,int n){
    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0;
    long long S2=0;
    for(int i=0;i<n;i++){
        S+=nums[i];
        S2+=nums[i]*nums[i];
    }
    long long val1=S-SN;
    long long val2=S2-S2N;
    val2=val2/val1;
    long long X=(val1+val2)/2;
    long long Y=X-val1;
    return{int(X),int(Y)};

}
int main(){
    vector<int> nums={3, 5, 4, 1, 1};
    int n=nums.size();
    vector<int> result=findMissingRepeatingNumbers(nums,n);
    cout<<"Values A and B are: "<<endl;
    for(int val : result){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
