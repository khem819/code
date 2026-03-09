#include<iostream>
#include<vector>

using namespace std;

//backtracking and merge part
void merge(vector<int>&arr,int st,int end,int mid){
    vector<int> temp;
    int i=st,j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
        
    }

    //if the last element is remaining in any case
    while (i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
    while (j<=end)
        {
            temp.push_back(arr[j]);
            j++;
        }

    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
}

//main function

void mergesort(vector<int>&arr,int st,int end){
   if(st<end){
    int mid=st+(end-st)/2;

    mergesort(arr,st,mid);//left half
    mergesort(arr,mid+1,end);//right half

    merge(arr,st,end,mid);


   }
}

int main(){
    vector<int> arr={12,-31,98,-8,32,17};

    mergesort(arr,0,arr.size()-1);

    cout<<"sorted array: ";
    for(int x: arr) cout<<x<<" ";
    cout<<endl;

    return 0;
}