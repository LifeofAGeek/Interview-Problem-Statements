#include <bits/stdc++.h>
    using namespace std;

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>> arr[i];
        sort(arr, arr+n);
        
        int min, max, min1, max1, count =1, max_count=1;
            min = min1 = max = max1 = arr[0];

         for(int i=1; i<n; i++){
         	if(arr[i] == (arr[i-1]+1)){
                 max1 = arr[i];
                count++;
                if(count > max_count)   max_count = count; 
             }
             else{
                 if(count >= max_count){
                     min = min1;
                     max = max1;
                 }
                 count = 1;
                 min1 = arr[i];
                 max1 = arr[i];
             }
		 }
          if(count >= max_count){
                     min = min1;
                     max = max1;
                 }
         cout<<"range: (" << min <<", " << max <<")"<< endl;
    }
   return 0;
}
