#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int> &nums,int target){
    int starting=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int upper=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    int ending=upper-1;
    if (starting == nums.size() || nums[starting] != target)
        return {-1,-1};

    return{starting,ending};
}
int main(){
    vector<int> nums={5, 7, 7, 8, 8, 10};
    int target=8;
    vector<int> result=searchRange(nums,target);
    cout<<" starting and ending position of a given target value: ";
    cout<<result[0]<<" "<<result[1];

}