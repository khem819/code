#include<iostream>
using namespace std;

int gcd(int a, int b){

    while(a>0 && b>0){
     if(a>b){
        a=a%b;
     }
     else
     {
        b=b%a;
     }
    }
    if(a==0) return b;
     return a;
}

int lcm(int a,int b){
    int kgcd=gcd(a,b);
    return (a*b)/kgcd;
}

int main(){
    cout<< lcm(5,8)<<endl;
    return 0;
}
