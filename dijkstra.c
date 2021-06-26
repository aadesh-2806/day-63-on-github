#include<stdio.h>
int main()	//counting bucket sort //avl
{
	int a[5][5]={0,2,4,1,7,
				 2,0,5,3,7,
				 4,5,0,3,1,
				 1,3,3,0,4,
				 7,7,1,4,0};
	int s,d,i,mdn,x;
	int di[5],fn[5],t[5];
	printf("enter source: ");
	scanf("%d",&s);
	printf("enter destination: ");
	scanf("%d",&d);
	for(i=0;i<5;i++)
	{
		di[i]=10000;
		fn[i]=10000;
		t[i]=0;
	}
	di[s]=0;
	fn[s]=s;
	mdn=s;
	while(mdn!=d)
	{
		/*calculate new distances*/
		for(i=0;i<5;i++)
		{
			x=di[mdn]+a[mdn][i];
			if (x<di[i])
			{
				di[i]=x;
				fn[i]=mdn;
				t[i]=0;
			}
		}
		t[mdn]=1;

		/*find new min distance node with t[mdn]=0*/
		i=0;
		while(i<5 && t[i]==1)
			i++;
		mdn=i;
		for(i=mdn+1;i<5;i++)
			if(t[i]==0 && di[i]<di[mdn])
				mdn=i;
	}
	printf("printing the result:\n");
	x=d;
	while(x!=s)
	{
		printf("distance=%d,node=%d\n",di[x],fn[x]);
		x=fn[x];
	}
}
