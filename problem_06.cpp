#include<iostream>
// #include <bits/stdc++.h>
#define ll long long
using namespace std;
int partition(int *arr,int s,int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1 ; i <= e;i++){
        if(arr[i] < pivot){
            cnt++; //find no. of element less than pivot
        }
    } 
    int pivotindex = s + cnt; // index of the pivot element 
    swap(arr[s],arr[pivotindex]); //placing pivot element to the right placed
    //checking the left and right part of the pivot element 
    //?ele. at left should be less than pivot 
    //?ele. at right should be greater than pivot
    int i=s,j=e;
    while (i < pivotindex && j > pivotindex)
    {
        if(arr[i] < pivot){
            i++;
        }
        if(arr[j] > pivot){
            j--;
        }
        else if(i < pivotindex && j > pivotindex){
            swap(arr[i++],arr[j++]);
        }
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e){
    if(s >= e)
    {
        return ; // base case 
    }
   int p = partition(arr,s,e); //finding the partition point
   //left part 
   quicksort(arr,s,p-1);
   //right part
   quicksort(arr,p+1,e);
        
}  
int main()
{ 
int arr[6]={3,2,6,8,1,1};
quicksort(arr,0,5);
for(int i=0 ;i < 6;i++){
    cout << arr[i] << " ";
}

return 0;
}