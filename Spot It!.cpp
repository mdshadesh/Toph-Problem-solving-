#include<iostream>
int arr[102];
using namespace std;
void value(){
    for(int i=0;i<=101;i++)
    {
        int n = i*i-i+1;
        arr[i] = n;
    }
}
int main()
{
	value();
	int t,x;
	cin>>t;
	while(t--){
	    cin>>x;
	    int l=1;
	   int r = 101;
	   if(x==1){
	       cout<<2<<endl;
	   }else{
	    while(l<=r){
	        int mid = (l+r)/2;
	        if(arr[mid]>=x && arr[mid-1]<x){
	            cout<<arr[mid]<<endl;
	            break;
	        }
	        else if(arr[mid]<x){
	            l = mid+1;
	        }else{
	            r = mid-1;
	        }
	    }
	}
  }
}