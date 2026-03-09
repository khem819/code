#include <iostream>
using namespace std;

bool armstrong(int n){
   int num=n;
   int cnum=0;
    while(n !=0){
        int digit=n % 10;
       cnum+=(digit*digit*digit);
        n=n/10;
    }
    return cnum==num;
}

int main() {
    int n = 153;
    
    if(armstrong(n)){
        cout<<"number is armstronge";
    }
    else{
       cout<<"number isnot armstronge"; 
    }
    
    return 0;
}
