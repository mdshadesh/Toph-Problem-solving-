#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()

int main(){
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;
        string man[x],woman[y];
        string up = "" , left = "" , upinv = "", leftinv = "";
        for(int i = 0 ; i < x ; i++){
            bool xase = false;
            cin>>man[i];
            for(int j = 0 ; j < y ; j++){
                if(man[i][j]=='X')xase = true;
            }
            if(xase==false){
                up = man[i];
                upinv = "";
                for(char v:up){

                    if(v=='W')upinv+= string(1,'B');
                    else upinv+= string(1,'W');
                }
            }
        }
        for(int i = 0 ; i < y ; i++){
            bool xase = false;
            string temp = "";
            for(int j = 0 ; j < x ; j++){
                temp+=man[j][i];
                if(man[j][i]=='X')xase = true;
            }
            woman[i] = temp;
            if(xase==false){
                    left = temp;
                    leftinv = "";
                    for(char v:left){

                        if(v=='W')leftinv += string(1,'B');
                        else leftinv+= string(1,'W');
                    }
                }
        }
        if(up!=""){
            for(int i = 0 ; i < x ; i++){
                int inv = false;
                for(int j = 0 ; j < y; j++){
                    if(up[j]!=man[i][j] && man[i][j]!='X')inv = true;
                }
                if(inv)cout<<upinv<<endl;
                else cout<<up<<endl;
            }
        }
        else if(left!=""){
            for(int i = 0 ; i < y ; i++){
                int inv = false;
                for(int j = 0 ; j < x; j++){
                    if(left[j]!=woman[i][j] && woman[i][j]!='X')inv = true;
                }
                if(inv)woman[i] = leftinv;
                else woman[i] = left;
            }
            for(int i = 0 ; i < x ; i++){
                for(int j = 0 ; j < y ; j++){
                    cout<<woman[j][i];
                }
                cout<<endl;
            }
        }
        else{
            for(int i = 0 ; i < x ; i++)cout<<string(y,'W')<<endl;
        }
    } 
}