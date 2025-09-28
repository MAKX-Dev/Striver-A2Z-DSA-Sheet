#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int maxProduct(vector<int> arr,int n){
    int ans=INT_MIN;
    int suff=1,pref=1;
    for(int i=0;i<n;i++){
        if(pref==0) pref=1;
        if(suff==0) suff=1;
        pref=pref*arr[i];
        suff=suff*arr[n-i-1];
        ans=max(ans,max(pref,suff));
    }
    return ans;

}
int main(){
    vector<int> arr={2,3,-2,4};
    int n=arr.size();
    int result=maxProduct(arr,n);
    cout<<"Maximum product through subarray is: "<<result<<endl;
    return 0;
}