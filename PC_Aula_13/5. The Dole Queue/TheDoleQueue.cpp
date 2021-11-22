#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int n,k,m;
int A[30];
int go(int p,int d,int t){
	while(t--){
		do{
			p=(p+d+n-1)%n+1;
		}while(A[p]==0);
	}
	return p;
}
main(){
	while(cin>>n>>k>>m&&n){
		 for(int i=1;i<=n;i++)
		 A[i]=i;
		 int left=n;int p1=n;
		 int p2=1;
		 while(left){
		 	p1=go(p1,1,k);
		 	p2=go(p2,-1,m);
		 	printf("%3d",p1);
		 	left--;
		 	if(p2!=p1){
				printf("%3d",p2);
		 		left--;
		 	}
		 	A[p1]=A[p2]=0;
		 	if(left)
		 	cout<<",";
		 }
		 cout<<endl;
	}
}