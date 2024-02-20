
#include<iostream>
using namespace std;
int merge(arr[],l,m,r){
    int comparisons=0;
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[m+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<= R[i]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
        comparisons++;
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
    return comparisons;
}
long long mergesort(int arr[],int l,int r){
    long long comparisons=0;
    if(l<r){
        int m=l+(r-l)/2;
        comparisons+=mergesort(arr,l,m);
        comparisons+=mergesort(arr,m+1,r);
        comparisons+=merge(arr,l,m,r);
    }
    return comparisons;
}

int main(){
    int arr={12,5,8,2,3,1,78};
    int n=sizeof(arr)/sizeof(arr[0]);

    long long comparisons=mergesort(arr,0,n-1);
    
}