#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
 vector <int> twoStacksSort(vector<int> numbers){
     int size=numbers.size();
     stack<int>s;
     stack<int>tmp;
     stack<int>res;
     for(int i=size-1;i>=0;i--){
         s.push(numbers[i]);
    
     }
     while(!s.empty()){
         int top=s.top();
         s.pop();
         if(tmp.empty() ||top<=tmp.top()){
             tmp.push(top);
         }else{
             while(!tmp.empty() && top>tmp.top()){
                 s.push(tmp.top());
                 tmp.pop();
             }
             tmp.push(top);
         }
     }
     while(!tmp.empty()){
         s.push(tmp.top());
         tmp.pop();
     }
     while(!s.empty()){
         res.push_back(s.top());
         s.pop();
     }
     return res;
 }
}
