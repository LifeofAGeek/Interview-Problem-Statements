#include<bits/stdc++.h>
using namespace std;

void NGE_On2(int arr[], int n)
{
    int next;
    for(int i=0;i<n;i++)
    {
        next=-1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i]){
                next=arr[j];
                break;}
        }
        cout<<arr[i]<<"-->"<<next<<endl;
    }
}

int main()
{
    int a[]={3, 2, 5, 6, 9, 8};
    int n=sizeof(a)/sizeof(a[0]);
    NGE_On2(a,n);
}
