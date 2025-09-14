#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int> &arr,int n,int num){
    for(int i=0;i<n;i++){
        if(i==num){
            return i;
        }
        
    }
    return -1;


}
int main(){
    int n;
    cin>>n;
    int num;
    cin>>num;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    int ans=linearSearch(arr,n,num);
    cout<<ans<<endl;
    
}