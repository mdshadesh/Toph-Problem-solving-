/* Naimul Hasan SHadesh 
 Sonargaon University */

#include <iostream>

using namespace std;

int isPrime(int n)
{
 if(n<=1) return false;
 if(n<=3) return true;

 if(n%2==0 || n%3==0)
  return false;
 // Main Code

 for(int i=5; i*i<=n; i+=6)
 {
  if(n%i==0 || n%(i+2)==0)
   return false;
 }

 return true;
}


int main() {
 int n;
 cin>>n;
 int i=2,c=0;
 while(1)
 {
  
  if(isPrime(i)==true)
  c++;
  if(c==n)
  {
   cout<<i<<endl;
   break;
  }
  i++;
 }
  
 return 0;
}