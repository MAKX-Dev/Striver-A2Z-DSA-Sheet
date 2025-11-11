#include<bits/stdc++.h>
using namespace std;
bool isomorphicString(string s,string t){
    if(s.size()!=t.size()) return false;
    unordered_map<char,char> map_sTOt;
    unordered_map<char,bool> used_in_t;
    for(int i=0;i<s.size();i++){
        char c1=s[i];
        char c2=t[i];
        if(map_sTOt.count(c1)){
            if(map_sTOt[c1]!=c2) return false;
        }
        else{
            if(used_in_t[c2]) return false;
            map_sTOt[c1]=c2;
            used_in_t[c2]=true;
        }
    }
    return true;
}
int main(){
    string s = "apple"; 
    string t = "bbnbm" ;
    if(isomorphicString(s,t)){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}