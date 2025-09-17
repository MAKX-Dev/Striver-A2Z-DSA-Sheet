#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int> &arr,int n){
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if (cnt==0){
            cnt=1;
            el=arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }

    }
    int cnt1=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el){
            cnt1++;
        }
    }
    if(cnt1>n/2){
        return el;
    }
    return -1;


}
int main(){
    vector<int> arr={7,0,0,1,7,7,2,7,7};
    int n=arr.size();
    int result=majorityElement(arr,n);
    cout<<"Element appeared in majority is: "<<result<<endl;
}   
