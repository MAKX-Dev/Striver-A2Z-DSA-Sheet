#include<iostream>
using namespace std;
void SelectSort(int n,int arr[]){
    for(int i=0;i<(n-1);i++){
        int min=i;
        for(int j=i+1;j<=(n-1);j++){
            if(arr[j]<arr[min]){
                min=j;
            }
            swap(arr[i],arr[min]);
        }
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i;i<n;i++){
        cin>>arr[i];
    }
    SelectSort(n,arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
    return 0;
}