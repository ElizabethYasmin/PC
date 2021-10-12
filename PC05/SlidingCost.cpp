#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;
ll arr[200005];
multiset<ll> RighT;
multiset<ll> LefT;
ll qLeft, qRight;

void inserT(ll VaLue){
	ll a = *LefT.rbegin();
	if(a < VaLue){
		RighT.insert(VaLue); qRight += VaLue;
		if(RighT.size() > k/2){
			ll moving = *RighT.begin();
			LefT.insert(moving); qLeft += moving;
			RighT.erase(RighT.find(moving)); qRight -= moving;
		}
	}
	else{
		LefT.insert(VaLue); qLeft += VaLue;
		if(LefT.size() > (k + 1)/2){
			ll moving = *LefT.rbegin();
			RighT.insert(*LefT.rbegin()); qRight += moving;
			LefT.erase(LefT.find(*LefT.rbegin())); qLeft -= moving;
		}
	}
}

void DeleTe(ll VaLue){
	if(RighT.find(VaLue) != RighT.end()) RighT.erase(RighT.find(VaLue)), qRight -= VaLue;
	else LefT.erase(LefT.find(VaLue)), qLeft -= VaLue;
	if(LefT.empty()){
		ll moving = *RighT.begin();
		LefT.insert(*RighT.begin()); qLeft += moving;
		RighT.erase(RighT.find(*RighT.begin())); qRight -= moving;
	}
}

ll med(){ return (k%2 == 0) ? 0 : (*LefT.rbegin()); }


void slidingCost(){
    LefT.insert(arr[0]); qLeft += arr[0];
	for(ll i = 1; i < k; i++) inserT(arr[i]);
	cout << qRight - qLeft + med(); if(n!=1) cout << " ";
	for(ll i = k; i < n; i++){
		if(k == 1){
			inserT(arr[i]);
			DeleTe(arr[i - k]);
		}
		else{
			DeleTe(arr[i - k]);
			inserT(arr[i]);
		}
		cout << qRight - qLeft + med(); if(i != n -1) cout << " ";
	}
	cout << endl;
}


//Entrada:
//8 3
//2 4 3 5 8 1 2 1

//Salida:
//2 2 5 7 7 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> n >> k;
	for(ll i = 0; i < n; i++) cin >> arr[i];
    
	slidingCost();
}