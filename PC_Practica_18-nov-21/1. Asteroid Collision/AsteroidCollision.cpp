
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> v;
        for(auto i:asteroids) {
            if(i<0){
                int n = v.size();
                if(n==0){
                  v.push_back(i);
                }else{
                    if(v.back()<0)
                        v.push_back(i);
                    else{
                        int d=abs(i);
                        if(v.back()<=d){
                            int f=0;
                            while(v.back()>0 && v.back()<=d) {  
                                if(v.back()==d){
                                    v.pop_back();
                                    f=1;
                                    break;
                                }
                                v.pop_back();
                                if(v.size()==0)
                                    break;
                            }
                            if(v.size()==0 && f==0)
                                v.push_back(i);
                            else if(v.size()!=0 && f==0 ) {
                                if(v.back()<0)
                                   v.push_back(i);
                            }
                        } 
                            
                    }
                }
            }else{
                v.push_back(i);
            }   
        }
        return v;
    }

    int main(){
        vector<int> v= {5,10,-5};

        for (size_t i = 0; i < asteroidCollision(v).size(); ++i) {
        cout << asteroidCollision(v).at(i) << "; ";
        }

    }