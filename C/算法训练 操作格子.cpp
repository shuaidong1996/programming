#include<stdio.h>
#include<malloc.h>
int arr[100000];
int change(int a,int b)
{
	a-=1;
	arr[a]  = b;
}
int sum(int a,int b)
{
	a-=1,b-=1;
	int sum=0,i;
	for(i = a;i<=b;i++)
	sum+=arr[i];
	return sum;
}
int max(int a,int b)
{
	a-=1,b-=1;
	int i,Max = arr[a];
	for(i=a;i<=b;i++)
	if(Max<arr[i])
	Max = arr[i];
	return Max;
}
int main()
{
	int n,m,i,j,cin[3];
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	int*S;
	S = (int*)malloc(sizeof(int)*m); 

	for(i=0,j=-1;i<m;i++)
	{
		scanf("%d%d%d",&cin[0],&cin[1],&cin[2]);

		if(cin[0] == 1)
		change(cin[1],cin[2]);
		if(cin[0] == 2)
		S[++j] = sum(cin[1],cin[2]);
		if(cin[0] == 3)
		S[++j] = max(cin[1],cin[2]);
	}
	
	for(i=0;i<=j;i++)
	printf("%d\n",S[i]);
	
	return 0;
 } 
/*
有n个格子，从左到右放成一排，编号为1-n。

共有m次操作，有3种操作类型：

1.修改一个格子的权值，

2.求连续一段格子权值和，

3.求连续一段格子的最大值。

对于每个2、3操作输出你所求出的结果。

输入格式
第一行2个整数n，m。

接下来一行n个整数表示n个格子的初始权值。

接下来m行，每行3个整数p,x,y，p表示操作类型，p=1时表示修改格子x的权值为y，p=2时表示求区间[x,y]内格子权值和，p=3时表示求区间[x,y]内格子最大的权值。

输出格式
有若干行，行数等于p=2或3的操作总数。

每行1个整数，对应了每个p=2或3操作的结果。

样例输入
4 3
1 2 3 4
2 1 3
1 4 3
3 1 4
样例输出
6
3
数据规模与约定
对于20%的数据n <= 100，m <= 200。

对于50%的数据n <= 5000，m <= 5000。

对于100%的数据1 <= n <= 100000，m <= 100000，0 <= 格子权值 <= 10000。
*/
