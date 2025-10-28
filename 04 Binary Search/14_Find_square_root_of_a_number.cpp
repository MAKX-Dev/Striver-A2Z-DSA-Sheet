#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n){
    if(n==0) return 0;
    int low=1;
    int high=n;
    int ans=-1;
    while(low<=high){
        long long mid=low+(high-low)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;

        }
        else{
            high=mid-1;
        }
        }
        return ans;
}
int main(){
    int n=28;
    int result=floorSqrt(n);
    cout<<"floor value of sqrt(n) is: "<<result<<endl;
}