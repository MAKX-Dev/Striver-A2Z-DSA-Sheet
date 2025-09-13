#include<iostream>
#include<vector>
using namespace std;
bool checkS(vector<int> &arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]){

        }
        else
        return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector <int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=checkS(arr,n);
    cout<<result<<endl;


}