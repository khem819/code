#include<iostream>
#include<vector>

using namespace std;
bool searchIn(vector<vector<int>>& mat,int target,int rows){
    int n=mat[0].size();
    int st=0,end=n-1;

    while (st<=end)
    {
       int mid=st+(end-st)/2;
       if(target == mat[rows][mid]){
          return true;
       } 
       else if( target > mat[rows][mid]){
        st=mid+1;
       }
       else{
        end=mid-1;
       }
    }
    return false;
}


bool searchmatrix(vector<vector<int>>& mat,int target){
    int m=mat.size();
    int n=mat[0].size();
    int startrow=0;
    int endrow=m-1;

    while (startrow<=endrow){
        int mid=startrow+(endrow-startrow)/2;

        if(target >= mat[mid][0] && target <= mat[mid][n-1]){
            return searchIn(mat,target,mid);

        }else if(target > mat[mid][n-1]){
            startrow=mid+1;
        }
        else{
            endrow=mid-1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> mat={{1,2,3,4},{1,5,9,7},{7,5,3,9},{11,25,85,45}};
    int target=21;

   if (searchmatrix(mat, target)) {
        cout << "Target found" << endl;
    } else {
        cout << "Target not found" << endl;
    }

   return 0;
}