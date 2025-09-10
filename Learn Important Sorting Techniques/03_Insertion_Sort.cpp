#include<iostream>
using namespace std;
void SelectionSort(int n,int arr[]){
    for(int i=0;i<=(n-1);i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }

    }


}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SelectionSort(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}