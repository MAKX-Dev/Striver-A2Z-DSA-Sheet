#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number:  "<<endl;
    cin>>n;
    int revN=0;
    int dup=n;
    while(n>0){
    int lastdigit=n%10;
    revN=revN*10+lastdigit;
        n=n/10;
    }
    if(revN==dup){
        cout<<"Yes it's Polindrome"<<endl;
    }
    else{
        cout<<"No it's not a Polindrom"<<endl;
    }
   




   
}