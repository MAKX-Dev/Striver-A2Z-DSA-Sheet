#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {
       string result="";
       int balance=0;
       for(char c : s){
           if(c=='('){
               if(balance>0) result.push_back(c);
               balance++;
           } 
           else{ // c == ')'
               balance--;
               if(balance>0) result.push_back(c);
           }
       }
       return result;
    }
int main(){
    string s="((()))";
   string ans=removeOuterParentheses(s);
   cout<<ans<<endl;
   return 0;
}