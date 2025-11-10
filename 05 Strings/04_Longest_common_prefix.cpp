#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
    if (strs.empty()) return "";
    string prefix=strs[0];
    for(int i=1;i<strs.size();i++){
        int j=0;
        while(j<prefix.size() && j<strs[i].size() && prefix[j]==strs[i][j]){
        j++;
        if(prefix.empty()) break;
        }
        prefix=prefix.substr(0,j);
    }
    return prefix;
}
int main(){
    vector<string> str;
    str.push_back("flowers");
    str.push_back("flow");
    str.push_back("fly");
    str.push_back("flight");
    cout<<longestCommonPrefix(str)<<endl;
    return 0;
}