#include<stdio.h>
// 01背包问题 	最大容量为 M 物品个数为 N  每个物品的大小为 w[]  每个物品的价值为 p[] 
int val[202][5001];			//一开始是定义val[202][202]  和百度上的一模一样   就是运行出错  还以为闯鬼了  老出错  原来当数据大了 就存不下了 包的容量最大有5000 
int max(int a,int b)
{
	return (a>b)?a:b;
}
int main()
{
	int i,j,N,M,w[202],p[202];
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
	scanf("%d%d",&w[i],&p[i]);
	for(i=1;i<=N;i++)											// i  就变成了物品的个数  
	{
		for(j=1;j<=M;j++)										//  j  变成了包大小 
		{
			if(w[i]<=j)
			val[i][j]=max(   val[i-1][j]    ,val[i-1][   j-w[i]  ]   +p[i]  );
			else
			val[i][j]=val[i-1][j];
		}
	}
	printf("%d\n",val[N][M]);
	for(i=0;i<=N;i++)
	{
	for(int j=0;j<=M;j++)
	printf("%d\t",val[i][j]);
	printf("\n");
	}
	return 0;
}
/*测试数据
in
100 1000
71 26
34 59
82 30
23 19
1 66
88 85
12 94
57 8
10 3
68 44
5 5
33 1
37 41
69 82
98 76
24 1
26 12
83 81
16 73
26 32
18 74
43 54
52 62
71 41
22 19
65 10
68 65
8 53
40 56
40 53
24 70
72 66
16 58
34 22
10 72
19 33
28 96
13 88
34 68
98 45
29 44
31 61
79 78
33 78
60 6
74 66
44 11
56 59
54 83
17 48
63 52
83 7
100 51
54 37
10 89
5 72
79 23
42 52
65 55
93 44
52 57
64 45
85 11
68 90
54 31
62 38
29 48
40 75
35 56
90 64
47 73
77 66
87 35
75 50
39 16
18 51
38 33
25 58
61 85
13 77
36 71
53 87
46 69
28 52
44 10
34 13
39 39
69 75
42 38
97 13
34 90
83 35
8 83
74 93
38 61
74 62
22 95
40 73
7 26
94 85
out
2614
*/ 

