#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    int n,a,b,c;
    string dept, session;
    cin>>n;
    while(n--){
        dept = session = "";
        scanf("%d-%d-%d",&a,&b,&c);
        if(a%10==1){
            session = "Spring";
        }
        else if(a%10==2){
            session = "Summer";
        }
        else if(a%10==3){
            session = "Autumn";
        }
        if(b==115) dept = "CSE";
        else if(b==141) dept = "EEE";
        else if(b==116) dept = "BBA";
        else if(b==117) dept = "LLB";
        else if(b==114) dept = "English";
        else if(b==111) dept = "Economics";
        cout<<dept<<" "<<session<<" 20";
        if(a/10<10)
            printf("0%d\n", a/10);
        else printf("%d\n", a/10);
    }
    return 0;
}