# include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){
    queue<int>s;

    s.push(1);
    s.push(2);
    s.push(3);

   queue<int>s2;
   s2.push(6);
   s2.push(9);
   s2.push(8);

   s2.swap(s);
  
   cout<<"output:"<<s.front()<<endl;
   
    return 0;
}