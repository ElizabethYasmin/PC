#include <iostream>
#include<vector>
using namespace std;
int main(){
    int t=0,l=0,s=0,ind=0;
    string suffix;
    vector<char> out;
    cin>>t;
    for(int i=0; i<t;i++){
        cin>>l>>s;
        out.assign(l,'-');
        bool imp=false;
        for(int j=0; j<s;j++){
            cin>>ind>>suffix;
            ind--;
            bool missing=false;
            for(int k=ind;k<ind+suffix.length();k++){
                if(suffix[k-ind]=='*'){missing=true;break;}
                if(out[k] !='-' && out[k]!=suffix[k-ind]){imp=true;break;}
                out[k]=suffix[k-ind];
            }
            if(missing==true){
                for(int k=l-1;k>=ind;k--){
                    if(suffix[k-l+suffix.length()]=='*'){break;}
                    if(out[k] != '-' && out[k]!=suffix[k-l+suffix.length()]){imp=true;break;}
                    out[k]=suffix[k-l+suffix.length()];
                }
            }
        }
        for(auto k : out){
            if(k=='-'){imp=true;break;}}
        if(imp==true){cout<<"IMPOSSIBLE\n";}
        else{for(auto k : out){cout<<k;}
            cout<<"\n";   
        }
    }
    return 0;
}