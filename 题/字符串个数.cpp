#include <stdio.h>
#include <string.h> 
int main()
{
	char s[]="\\123456\123456\t";
	printf("%d\n",strlen(s));
	
	
	printf("------------------�𰸽���-------------------\n");
	
	printf("%s\n",s);
	printf("\123   %c\n",83);
	
	int a = 0123;
	printf("%c",a);
}
/*
\123 ����8���� 1 * 8 *  8 + 2 * 8 + 3 = 83 
*/
