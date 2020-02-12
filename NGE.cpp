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

void printNGE(int arr[], int n) {
  stack < int > s;

  s.push(arr[0]);

  for (int i = 1; i < n; i++) {

    if (s.empty()) {
      s.push(arr[i]);
      continue;
    }

    while (s.empty() == false && s.top() < arr[i])
    {
        cout << s.top() << " --> " << arr[i] << endl;
        s.pop();
    }

    s.push(arr[i]);
  }

  while (s.empty() == false) {
    cout << s.top() << " --> " << -1 << endl;
    s.pop();
  }
}

int main()
{
    int a[]={3, 2, 5, 6, 9, 8};
    int b[]={11, 13, 21, 3};
    int n1=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);
    NGE_On2(a,n1);
    printNGE(b,n2);
}
