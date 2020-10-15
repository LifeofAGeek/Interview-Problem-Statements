#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n,i,j,p;
	cout<<"enter the outer number : ";
	cin>>n;
	cout<<"\n\n";
	for(i=0;i<(2*n-1);i++)
	{
	    for(j=0;j<(2*n-1);j++)
	    {
	        for(p=0;p<n;p++)
	        {
	            if(i==p||j==p||i==(2*n-2-p)||j==(2*n-2-p))
	            {
	                cout<<n-p<<" ";
	                break;
	            }
	        }
	        
	    }
	    cout<<"\n\n";
	}
	return 0;
}




// EXAMPLE
//-------------------------------

// enter the outer number : 3

//Output:
// 3 3 3 3 3
// 3 2 2 2 3
// 3 2 1 2 3
// 3 2 2 2 3
// 3 3 3 3 3