#include<bits/stdc++.h>
using namespace std;
using namespace std;
void findCombinations(int index, int target, vector<int>& candidates, 
                      vector<int>& currentCombination, vector<vector<int>>& allCombinations) {
    if(target==0){
        allCombinations.push_back(currentCombination);
        return;
    }
    if(target<0){
        return;
    }
    for (int i=index;i<candidates.size();i++){
        if (i>index && candidates[i]==candidates[i-1]){
            continue;
        }
        currentCombination.push_back(candidates[i]);
        findCombinations(i+1,target-candidates[i],candidates, 
                         currentCombination,allCombinations);
        currentCombination.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> allCombinations;
    vector<int> currentCombination;
    findCombinations(0,target,candidates,currentCombination,allCombinations);
    return allCombinations;
}

int main(){
    vector<int> candidates={2, 1, 7, 6, 1, 5};
    int target=8;
    
    vector<vector<int>> results=combinationSum2(candidates,target);
    cout<<"Combinations found:"<<endl;
    for (const auto& vec : results){
        cout<<"[ ";
        for (int num : vec){
            cout<<num<< " ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}