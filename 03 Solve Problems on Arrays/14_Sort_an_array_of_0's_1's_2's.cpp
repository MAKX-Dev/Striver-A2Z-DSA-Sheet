#include<iostream>
#include<vector>
using namespace std;
void zeroOneTwo(vector<int> &arr,int n){
    int low=0;
    int mid=0;
    int high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
    
        else if(arr[mid]==1){
            mid++;
        }
    
        else{ //arr[mid]==2
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    }


int main(){
    int n=5;
    vector<int> arr={1,0,2,1,0};
    zeroOneTwo(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}
