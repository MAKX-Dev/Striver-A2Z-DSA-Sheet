#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int> &arr,int n){
    int sum=(n*(n+1)/2);
    int s2=0;
    for(int i=0;i<n-1;i++){
        s2+=arr[i];
        
    }
    int ans=sum-s2;
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    int result=missingNumber(arr,n);
    cout<<"Missing number is: "<<result<<endl;
    return 0;
    
}
