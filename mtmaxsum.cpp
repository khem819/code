#include<iostream>

using namespace std;

int gtmax(int matrix[3][3],int rows,int cols){
    int maxrow= INT_MAX;
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
    

    
    cout<<gtmax(matrix,rows,cols)<<endl;
    return 0;
}

