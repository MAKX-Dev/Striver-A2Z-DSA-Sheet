#include<bits/stdc++.h>
using namespace std;
int sumOfElements(vector<int>a){
    int sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
    }
    return sum;
}
int countPartitions(vector<int> &a,int mid){
    int n=a.size();
    int partitions=1;
    long long subarraySum=0;
    for(int i=0;i<n;i++){
         if(a[i]>mid){
            return INT_MAX;
        }
        if(subarraySum+a[i]<=mid){
            subarraySum+=a[i];
        }
         else {
            partitions++;
            subarraySum=a[i];
        }
    }
    return partitions;
}
int largestSubarraySumMinimized(vector<int> &a,int k){
    if(a.empty()) return 0;
    int low=*max_element(a.begin(),a.end());
    int high=sumOfElements(a);
    while(low<=high){
        int mid=low+(high-low)/2;
    int partitions=countPartitions(a,mid);
        if(partitions>k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
int main(){
    vector<int> a={1, 2, 3, 4, 5};
    int k=3;
    int result=largestSubarraySumMinimized(a,k);
    cout<<result<<endl;
    return 0;

}