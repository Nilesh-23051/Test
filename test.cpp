 #include<bits/stdc++.h>
 using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void LeftRev(int *arr,int low,int k){
    
    for(int i=low,j=k-1;i<j;)
    {swap(arr[i],arr[j]);
    i++;
    j--;
    }
} 
void sortLRK(int arr[],int low,int high){
if(high==low){
    return;
}
int min=arr[low];
int minPointer=0;
/*Finding Minimum*/
for(int i=low+1;i<=high;i++){
    if(arr[i]<min){
        min=arr[i];
        minPointer=i;
    }
}
LeftRev(arr,low,minPointer+1);
sortLRK(arr,low+1,high);
}


 int main(){
    int n;
    cout<<"Enter Size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"\nEnter Element: ";
        cin>>arr[i];
    }
    sortLRK(arr,0,n-1);
    for(auto it:arr){
        cout<<it<<" ";
    }
 
 }