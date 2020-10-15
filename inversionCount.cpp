#include<iostream>

using namespace std;

//to count the number of inversion pairs in an array

int merge(int *a, int start, int end)	{
	int temp[100];
	int mid = (start+end)/2;
	int i=start, j=mid+1, k=start;
	int count = 0; //no of cross inversions
	
	while(i<=mid && j<=end)	{
		if(a[i]<=a[j])
			temp[k++] = a[i++];
		else	{
			temp[k++] = a[j++];
			count += mid - i + 1; 
		}
	}
	while(i<=mid)
		temp[k++] = a[i++];
	while(j<=end)
		temp[k++] = a[j++];
		
	for(int i=start;i<=end;i++)	{
		a[i] = temp[i];
	}
	
	return count;
}

int inversionCount(int a[], int start, int end)	{
	if(start>=end)
		return 0;
	int mid = (start+end)/2;
	int x = inversionCount(a, start, mid);
	int y = inversionCount(a, mid+1, end);
	int z = merge(a, start, end);
	return x + y + z;	
}

int main()	{
	int arr[] = {1, 5, 2, 6, 3, 0};
	//inversions go like -> (1, 0), (5, 3), (5, 2), (5, 0), (2, 0), (6, 0), (3, 0), (6, 3)
	cout<<inversionCount(arr, 0, 5);
	return 0;
}
