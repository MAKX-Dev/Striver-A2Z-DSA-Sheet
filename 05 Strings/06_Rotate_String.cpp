#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s,string goal){
    if(s.size()!=goal.size()) return false;
    string combine=s+s;
    return combine.find(goal)!=string::npos;
}
int main(){
    string s = "abcde" , goal = "cdeab";
    if(rotateString){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
}