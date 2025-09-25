#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> mergeOverlap (vector<vector<int>> arr,int n){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;


}
int main(){
    vector<vector<int>> arr={{5,7},{1,3},{4,6},{8,10}};
    int n=arr.size();
    vector<vector<int>> ans=mergeOverlap(arr,n);
    cout<<"The merged intervals are: "<<endl;
    for(auto it : ans){
        cout<<"["<< it[0] <<","<<it[1]<<"] ";
    }
    cout<<endl;
    return 0;

}