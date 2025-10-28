#include<bits/stdc++.h>
using namespace std;
void generate(int n,int openCount,int closeCount,string currentString,vector<string>& result){
    if(openCount==n && closeCount==n){
        result.push_back(currentString);
        return;
    }
    if(openCount<n){
        generate(n,openCount+1,closeCount,currentString+"(",result);
    }
    if(closeCount<openCount){
        generate(n,openCount,closeCount+1,currentString+")",result);
    }
}
vector<string> generateParenthesis(int n){
    vector<string>result;
    generate(n,0,0, "",result);
    return result;
}
int main(){
    int n=3;
    vector<string>allCombinations=generateParenthesis(n);
    for(const string& s : allCombinations){
        cout<<s<< " ";
    }
    cout<<endl;
    return 0;
}