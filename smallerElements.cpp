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
                s[i]=c++;}
        }
    }
}

int main()
{
    int a[]={3, 4, 9, 6, 1};

}
