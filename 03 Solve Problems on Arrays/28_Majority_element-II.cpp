#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
vector<int> majorityElementTwo(vector<int> &nums,int n){
    int cnt1=0;
    int cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && el2!=nums[i]){
            cnt1=1;
            el1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=el2){
            cnt2=1;
            el2=nums[i];
        }
        else if(el1==nums[i]){
            cnt1++;
        }
        else if(el2==nums[i]){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==nums[i]){
            cnt1++;
        }
        if(el2=nums[i]){
            cnt2++;
        }
    }
    int mini=int(n/3)+1;
        if(cnt1>=mini){
            ls.push_back(el1);
        }
        if(cnt2>=mini){
        ls.push_back(el2);          
        }
        
    sort(ls.begin(),ls.end());
    return ls;


}
int main(){
    vector<int> nums={1, 2, 1, 1, 3, 2, 2};
    int n=nums.size();
    vector<int> result=majorityElementTwo(nums,n);
    cout << "The majority elements are: ";
    for(auto it:result)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}