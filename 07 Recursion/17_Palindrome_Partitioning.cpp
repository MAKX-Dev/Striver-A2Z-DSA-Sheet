#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(const string &s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
void func(int index,vector<string>& partitionVec,vector<vector<string>> &allPossible,const string &s){
    if(index==(int)s.size()){
        allPossible.push_back(partitionVec);
        return;
    }
    for(int i=index;i<(int)s.size();i++){
        if(isPalindrome(s,index,i)){
            partitionVec.push_back(s.substr(index,i-index+1));
            func(i+1,partitionVec,allPossible,s);
            partitionVec.pop_back();
        }
    }
}
vector<vector<string>> partitionAll(const string &s){
    vector<string> partitionVec;
    vector<vector<string>> allPossible;
    func(0,partitionVec,allPossible,s);
    return allPossible;
}
int main(){
    string s="aabaa";
    vector<vector<string>>result=partitionAll(s);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<(j+1==result[i].size()?"":", ");
        }
        
    }
    return 0;
}
    

