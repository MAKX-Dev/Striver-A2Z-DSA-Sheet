#include<iostream>
#include<cmath>
using namespace std;
int main (){
    cout<<"Enter the Number:  "<<endl;
    int N;
    cin>>N;
    int temp=N;
    int count=0;
    int t=N;
    while(t>0){
        count++;
        t/=10;
    }
   int sum=0;
   temp=N;
   
    while(temp>0){
       int digit=temp%10;
       sum+=pow(digit,count);
       temp=temp/10;
       if(sum==N){
        cout<<"Armstrong"<<endl;

       }
       else{
        cout<<"Not Armstrong"<<endl;
       }
    }
    return 0;

}