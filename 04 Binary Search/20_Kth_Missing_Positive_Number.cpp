#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr,int k){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high+1+k;
}
int main(){
    vector<int> arr={1, 4, 6, 8, 9};
    int k=3;
    int result=findKthPositive(arr,k);
    cout<<"kᵗʰ missing positive number is: "<<result<<endl;
    return 0;
}
