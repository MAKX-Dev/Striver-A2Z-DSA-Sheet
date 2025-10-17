#include<iostream>
using namespace std;
int RemoveDuplicates(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;

}
int main(){
    int n=6;
    int arr[n]={1,2,2,3,3,4};
    n=sizeof(arr)/sizeof(arr[0]);
  int k=RemoveDuplicates(arr, n);
  for(int i=0;i<k;i++){
    cout<<arr[i]<<endl;
    
}
}