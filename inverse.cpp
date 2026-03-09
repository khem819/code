# include<iostream>
using namespace std;

int main(){
    int rows,cols; 

    cout<<"enter the rows and cols: ";
    cin>> rows>> cols; 

    int matrix[10][10],transpose[10][10];

     // input the matrix
     cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i <rows; i++) {
      for(int j=0;j< cols;j++){
        cin >> matrix[i][j];
      }  
    }
    
    //compute the transpose
    for (int i = 0; i < rows; i++){ 
        for(int j=0;j<cols;j++){
            transpose[j][i]=matrix[i][j];
        }
    }
   
    // display the transpose matrix
    cout<<"the transpose of the matrix\n";
    for(int i=0;i<=rows;i++){
        for (int j = 0; j < cols; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
    
return 0;
    
}