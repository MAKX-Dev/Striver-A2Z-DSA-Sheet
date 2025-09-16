#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int> &arr,int n){
    int XOR=0;
    for(int i=0;i<n;i++){
        XOR=XOR^arr[i];
    }
    return XOR;
}
int main(){
    int n=7;
    vector<int>arr={1,2,2,4,3,1,4};
    int result=singleNumber(arr,n);
    cout<<"Single number appeared in array is: "<<result<<endl;
    
}