#include<iostream>

using namespace std;

int main(){
    string s="Ac3?e3c&a";
    int n=s.length();
    string rev=" ";

    for(int i=n-1;i>=0;i--){
     rev+=s[i];
    }
    
    if(s==rev){
        cout<<"number is palindrome"<<endl;
    }
    else{
        cout<<"number isnot palindrome"<<endl;
    }
    return 0;
}