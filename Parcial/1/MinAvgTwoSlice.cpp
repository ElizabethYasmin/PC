//MinAvgTwoSlice
//Elizabeth Yasmin Huanca Parqui
//20190748
//----------------------------------------------------------------
//Find the minimal average of any slice containing at least two elements
//----------------------------------------------------------------


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A) {
    int solut = 0;
    double Valuemin = (A[0] + A[1]) / 2;
    int N = A.size();
    for (int i = 0; i < N - 1; i++){
        double avg = (A[i] + A[i+1])/2.0;
        if (avg < Valuemin){
            Valuemin = avg;
            solut = i;
        }
    }
    for (int i = 0; i < N - 2; i++){
        double avg = (A[i] + A[i+1] + A[i+2])/3.0;
        if (avg < Valuemin){
            Valuemin = avg;
            solut = i;
        }
    }
    return solut;
}
//Entrada: [4 , 2 , 2 , 5 , 1 , 5 , 8 ]
//Salida: 1
int main(){
    vector<int> ar ={ 4 , 2 , 2 , 5 , 1 , 5 , 8 };
    cout<<solution(ar);
    return 0;
}




