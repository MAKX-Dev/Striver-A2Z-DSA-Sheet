#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> leaders(vector<int> &arr,int n){
    int maxi=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
           ans.push_back(arr[i]);
        }
        maxi=max(maxi,arr[i]);

    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int> arr={1, 2, 5, 3, 1, 2};
    int n=arr.size();
    vector<int> ans=leaders(arr,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}