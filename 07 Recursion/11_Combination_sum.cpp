#include<bits/stdc++.h>
using namespace std;
void findCombinations(int index,int target,vector<int>& candidates, vector<int>& currentCombination,vector<vector<int>>& allCombinations){
    if(index==candidates.size()){
        if(target==0){
            allCombinations.push_back(currentCombination);
        }
        return;
    }
    if(candidates[index]<=target){
        currentCombination.push_back(candidates[index]);
        findCombinations(index,target-candidates[index],candidates, 
                         currentCombination,allCombinations);
        currentCombination.pop_back();
    }
    findCombinations(index+1,target,candidates, 
                     currentCombination,allCombinations);
}
vector<vector<int>> combinationSum(vector<int>& candidates,int target){
    vector<vector<int>> allCombinations;
    vector<int> currentCombination;
    findCombinations(0,target,candidates,currentCombination,allCombinations);
    return allCombinations;
}
int main(){
    vector<int> candidates={2, 3, 6, 7};
    int target=7;
    
    vector<vector<int>> results=combinationSum(candidates, target);
    
    cout<<"Combinations found:" <<endl;
    for (const auto& vec : results){
        cout<<"[ ";
        for(int num : vec){
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
