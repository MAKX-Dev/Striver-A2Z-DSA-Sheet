#include<bits/stdc++.h>
using namespace std;
int countOccurrences(vector<int> arr,int target){
    int starting=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
    int upper=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
    int ending=upper-1;
    if(starting==arr.size() || arr[starting]!=target){
        return 0;
    }
    

    int cnt=(ending-starting)+1;
    return cnt;
}
int main(){
    vector<int> arr={0, 0, 1, 1, 1, 2, 3};
    int target=6;
    int result=countOccurrences(arr,target);
    cout<<"count of occurrences of target in the array is: "<<result<<endl;
}