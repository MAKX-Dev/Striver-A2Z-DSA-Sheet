#include<bits/stdc++.h>
using namespace std;
string largeOddNum(string& s){
    int n=s.size();
    string num="";
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2==1){
                return s.substr(0,i+1);
            }
        }
        return "";
}
int main(){
    string s = "214638";
    string result=largeOddNum(s);
    cout<<result<<endl;
    return 0;
}