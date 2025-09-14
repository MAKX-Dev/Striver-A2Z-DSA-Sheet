#include<iostream>
#include<vector>
using namespace std;
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex=f(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);

    }
}
    vector<int> quickSort(vector<int> arr){
        qs(arr,0,arr.size()-1);
        return arr;
    }

    int f(vector<int> &arr,int low,int high) {
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(arr[i]<arr[pivot] && i<=high-1){
                i++;
            }
            while(arr[j]>arr[pivot] && j>=low-1){
                j--;
            }


        
        if(i<j){
            swap(arr[i],arr[j]);
        }
        

    }
    return j;
      
    
    }


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr = quickSort(arr);

    
   //After Quick Sort
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}