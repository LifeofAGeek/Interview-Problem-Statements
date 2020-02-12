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
            if(arr[j]>arr[i])
                next=arr[j];
                break;
        }
        cout<<arr[i]<<"-->"<<next<<endl;
    }
}
