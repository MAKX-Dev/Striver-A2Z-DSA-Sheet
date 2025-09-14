#include<iostream>
using namespace std;
int cntDigits(int n){
   
    int i=0;
    int cnt=0;
    while(n>0){
        
        
        n=n/10;
        cnt++;

    }
    return cnt;
}
int main(){
    int n;
    cout<<"Enter a number:  "<<endl;
    cin>>n;
    int digitCount=cntDigits(n);
    cout<<"The number of digits is:  "<<digitCount<<endl;
}
