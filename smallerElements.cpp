#include<bits/stdc++.h>
using namespace std;

void FindSmaller(int arr[], int n)
{
    int s[n],c;
    for(int i=0;i<n;i++)
    {
        c=0;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i]){
                c++;}
        }s[i]=c;
    }
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
}

int main()
{
    int a[]={3, 4, 9, 6, 1};
    int n=sizeof(a)/sizeof(a[0]);
    FindSmaller(a,n);
}
