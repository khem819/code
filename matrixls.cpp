#include<iostream>

using namespace std;

int linear(int matrix[3][3],int rows,int cols,int k){
     for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
       if(matrix[i][j]==k){
           return true;
       }
    }
}
return false;
}


int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rows=3;
    int cols=3;
    

    
    cout<<linear(matrix,rows,cols,8)<<endl;
    return 0;
}