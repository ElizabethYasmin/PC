//GenomicRangeQuery
//Elizabeth Yasmin Huanca Parqui
//20190748
//----------------------------------------------------------------
//Find the minimal nucleotide from a range of sequence DNA.
//----------------------------------------------------------------


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int len_S = S.length(); 
    int len_P = P.size();
    int len_Q = Q.size();
    int cum_A = 0; 
    int cum_C = 0;
    int cum_G = 0;
    int cum_T = 0; 

    vector<int> impact_A(len_S, 0);
    vector<int> impact_C(len_S, 0);
    vector<int> impact_G(len_S, 0);
    vector<int> impact_T(len_S, 0);

    vector<int> res;

    for(int i=0; i<len_S; i++){
        if(S[i] == 'A'){
            cum_A += 1; //-->1
        }else if(S[i] == 'C'){
            cum_C += 1; //-->2
        }else if(S[i] == 'G'){
            cum_G += 1; //--> 3
        }else if(S[i] == 'T'){
            cum_T += 1; //--> 4
        }
        impact_A[i] = cum_A;
        impact_C[i] = cum_C;
        impact_G[i] = cum_G;
        impact_T[i] = cum_T;
    }

    for(int i=0; i<len_P; i++){
        int left = P[i];
        int right = Q[i];
        int min_val = 5;
        if((impact_A[right] - impact_A[left-1]) >0){
            min_val = min(1 , min_val);
        }else if((impact_C[right] - impact_C[left-1]) >0){
            min_val = min(2 , min_val);
        }else if((impact_G[right] - impact_G[left-1]) >0){
            min_val = min(3 , min_val);
        }else if((impact_T[right] - impact_T[left-1]) >0){
            min_val = min(4 , min_val);
        }
        res.push_back(min_val);
    }
    return res;
}


int main(){
    //Entrada: S = CAGCCTA
    //Entrada: P------------------
    //P[0] = 2    
    //P[1] = 5    
    //P[2] = 0  

    //Entrada: Q------------------
    //Q[0] = 4
    //Q[1] = 5
    //Q[2] = 6


    //Salida: [ 2, 4, 1 ]

    vector<int> P={2,5,0};
    vector<int> Q={4,5,6};
    string S="CAGCCTA";
    for (int i = 0; i < solution(S,P,Q).size(); ++i) {
        cout << solution(S,P,Q)[i] << " , ";
    }
    cout << endl;
}
