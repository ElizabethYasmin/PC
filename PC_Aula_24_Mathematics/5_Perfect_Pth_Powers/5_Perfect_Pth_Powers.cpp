#include <stdio.h>
#include <math.h>
#define zero 1e-6
int main(){
	double n;
	int temp2,temp3,flag;
	int i,max;
    while(1){
	scanf("%lf",&n);
    max=1;
	 flag=0;
	 if(n==0) break;
      if(n<0) { flag=1;n=-n;}
    if(flag==0){	
	  for(i=2;i<=31;i++){
		temp2=(int)floor(pow(n,1/(i*1.0)));
		temp3=(int)ceil(pow(n,1/(i*1.0)));
          if((fabs(pow(temp3,i)-n)<zero||fabs(pow(temp2,i)-n)<zero))
		     max=i;
	}
    }else {
    for(i=2;i<=31;i++){
		temp2=(int)floor(pow(n,1/(i*1.0)));
		temp3=(int)ceil(pow(n,1/(i*1.0)));
        if((fabs(pow(temp3,i)-n)<zero||fabs(pow(temp2,i)-n)<zero)&&(i&1))
		     max=i;
	}
    }
	printf("%d\n",max);
	}
	return 0;
}