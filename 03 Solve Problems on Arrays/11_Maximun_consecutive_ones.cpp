#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int findMaxConsecutiveOnes(vector <int> &arr,int n){
    int maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]=1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else{
            cnt=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }
    int result=findMaxConsecutiveOnes(arr,n);
    cout<<"Maximun consecutive ones: "<<result<<endl;
}