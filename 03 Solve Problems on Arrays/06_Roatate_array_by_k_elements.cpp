#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void leftrotate(vector<int> &arr,int n,int k){
    k=k%n;
    if(k==0){
        return;
    }
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
}
void rightrotate(vector<int> &arr,int n,int k){
    k=k%n;
    if(k==0){
        return;
    }
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end()-k);
    reverse(arr.begin(),arr.end());
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        leftrotate(arr,n,k);
        rightrotate(arr,n,k);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }
    }
    

}