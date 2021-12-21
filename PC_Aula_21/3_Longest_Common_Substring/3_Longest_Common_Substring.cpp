#include <bits/stdc++.h>
using namespace std;

void lcs(string arr){
    int n=arr.length(),m=0;
    map<string,pair<int,int>> sor;
    string sub="";
    
    for(int i=0;i<n;i++){
        if(isdigit(arr[i])){ 
            m++;
            continue;
        }
        sor[arr.substr(i)] = make_pair(m,0);
    }

    int k=0,cont=0;
    string prev;
    for(auto& j: sor){
        if(k>=1){
            cont=0;
            string temp=j.first;
            for(int i=0;i<temp.length();i++){
                if(i>=prev.length() && !isdigit(prev[i]) && !isdigit(temp[i])){
                    j.second.second=cont;
                    break;
                }
                if(prev[i]==temp[i]){ 
                    cont++;
                }
                else{
                    j.second.second=cont;
                    break;
                }

            }
        }
        prev=j.first;
        k++;
    }
    cout<<"lcp \t string \t color\n";
    for(auto j : sor){
        cout<<j.second.second<<" "<<j.first<<" \t"<<j.second.first<<"\n";
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> s={"AABC","BCDC","BCDE","CDED"};

    string arr;
    for(int i=0;i<4;i++){
        arr+=s[i]+to_string(i);
    }
    cout<<"INPUT: AABC, BCDC, BCDE, CDED \nOUTPUT: \n";
    lcs(arr);

    return 0;
}