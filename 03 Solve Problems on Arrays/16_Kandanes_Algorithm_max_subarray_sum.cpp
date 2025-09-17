#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxSubArray(vector<int> arr,int n){
    long long sum=0;
    int maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}
int main(){
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    int n=arr.size();
    int result=maxSubArray(arr,n);
    cout<<"Largest sum is: "<<result<<endl;

}