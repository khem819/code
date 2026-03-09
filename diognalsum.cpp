#include<iostream>

using namespace std;

int diogonalsum(int mat[4][4],int n){
    int sum=0;
    for(int i=0;i<n;i++){
       sum+=mat[i][i];

       if(i !=n-i-1){
        sum +=mat[i][n-i-1];
       }
    }
    return sum;
}
int main(){
    int matrix[4][4]={{1,2,3,2},{4,5,6,3},{7,8,9,4},{10,12,13,5}};
    int n=4;

    
    cout<<diogonalsum(matrix,n)<<endl;
    return 0;
}