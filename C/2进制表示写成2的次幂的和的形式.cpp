/*问题描述
　　任何一个正整数都可以用2进制表示，例如：137的2进制表示为10001001。
　　将这种2进制表示写成2的次幂的和的形式，令次幂高的排在前面，可得到如下表达式：137=2^7+2^3+2^0
　　现在约定幂次用括号来表示，即a^b表示为a（b）
　　此时，137可表示为：2（7）+2（3）+2（0）
　　进一步：7=2^2+2+2^0 （2^1用2表示）
　　3=2+2^0 
　　所以最后137可表示为：***********  2（2（2）+2+2（0））+2（2+2（0））+2（0）************************

　　又如：1315=2^10+2^8+2^5+2+1
　　所以1315最后可表示为：
　　2（2（2+2（0））+2）+   2（2（2+2（0）））+   2（2（2）+2（0））+  2  +2（0）*/

#include<stdio.h>
void convert_bin(int a)
{
	int n=0,i=0,arr[100];
	while(a)
	{
		if(a%2 == 1)
		arr[i++] = n;//计算出这个数 二进制中 1 的位置 
		n++;
		a/=2;
	}
	for(i--;i>=0;i--)
	{
		if(arr[i] == 0)
		printf("2(0)");
		
		else if(arr[i] == 1)
		printf("2");
		
		else if(arr[i] == 2)
		printf("2(2)");
		
		else if(arr[n] > 2)
		{
			printf("2(");
			convert_bin(arr[i]);
			printf(")");
		}
		
		if(i)
		printf("+");
	 } 
	 
}
int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		convert_bin(a);	
	}
	return 0;
 } 
 
 /*
 **太可惜了，这道题不是本人做出来的，相了很久， 没想出来，，思路都是错的
 **非常经典啊，一直想着2()作为字符串输出，，，其实完全不用，，循环到最内层的时候--直接输出 2（2）、2、2（0）
 **真心佩服 
 */ 
 
