#include<iostream>
#include<queue>
#include<map>
 
using namespace std;
 int main(){
    map<string,int>m;
    m["k"]=50;
    m["p"]=90;
    m["l"]=98;

    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
     
 }