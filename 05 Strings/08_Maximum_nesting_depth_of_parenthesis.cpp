#include<bits/stdc++.h>
using namespace std;
int maxDepth(string &s){
    int openBracket=0;
    int result=0;
    for(char ch : s){
        if(ch=='('){
           openBracket++;
        }
        else if(ch==')'){
            openBracket--;
        }
        result=max(result,openBracket);
    }
    return result;
}
int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    int result=maxDepth(s);
    cout<<result<<endl;
}