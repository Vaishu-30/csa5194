 #include<stdio.h>
 #include<string.h>
 #include<math.h>
 int main()
 {
 	int a,q,xa,xb,ya,yb,x,y,ka,kb,m,n;
 	printf("enter the value of a:");
 	scanf("%d",&a);
 	printf("enter the value of q:");
 	scanf("%d",&q);
 	printf("enter the value of xa:");
 	scanf("%d",&xa);
 	printf("enter the value of xb:");
 	scanf("%d",&xb);
 	x=pow(a,xa);
 	ya=x%q;
 	y=pow(a,xb);
 	yb=y%q;
 	m=pow(yb,xa);
 	ka=m%q;
 	n=pow(ya,xb);
 	kb=n%q;
 	printf("secret key of user a:%d",ka);
	 printf("secret key of user b:%d",kb);
	  }
