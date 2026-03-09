#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralorder(vector<vector<int>>&mat){
    int m=mat.size();
    int n=mat[0].size();
    int srow=0 , scol=0;
    int erow=m-1, ecol=n-1;
    vector<int>ans;

   while(srow <= erow && scol <=  ecol){
    //top
    for(int j=scol;j<=ecol;j++){
        ans.push_back(mat[srow][j]);
    }
    //right
   for(int i=scol+1;i<=erow;i++){
        ans.push_back(mat[i][ecol]);
    }
    //bottom
     for(int j=scol-1;j>=ecol;j--){
        if(scol==ecol){
            break;
        }
        ans.push_back(mat[erow][j]);
    }
    // left
    for(int i=erow-1;i>=srow+1;i--){
        if(erow == srow){
            break;
        }
        ans.push_back(mat[i][scol]);
    }
    srow++; scol++; erow--; ecol++;
    
}
return ans;
}

int main(){
    vector<vector<int>>mat={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

   vector<int>ans =spiralorder(mat);
   for(int x : ans) cout << x << " ";

    return 0;
}