//ȥ��ȫ���еĵݹ�ʵ��  
#include <stdio.h>  
#include <string.h>  
void Swap(char *a, char *b)  
{  
    char t = *a;  
    *a = *b;  
    *b = t;  
}  
//��pszStr�����У�[nBegin,nEnd)���Ƿ����������±�ΪnEnd���������  
bool IsSwap(char *pszStr, int nBegin, int nEnd)  
{  
    for (int i = nBegin; i < nEnd; i++)  
        if (pszStr[i] == pszStr[nEnd])  
            return false;  
    return true;  
}  
//k��ʾ��ǰѡȡ���ڼ�����,m��ʾ���ж�����.  
void AllRange(char *pszStr, int k, int m)  
{  
    if (k == m)  
    {  
        static int s_i = 1;  
        printf("  ��%3d������\t%s\n", s_i++, pszStr);  
    }  
    else  
    {  
        for (int i = k; i <= m; i++) //��i�����ֱ�������������ֽ������ܵõ��µ�����  
        {  
            if (IsSwap(pszStr, k, i))  
            {  
                Swap(pszStr + k, pszStr + i);  
                AllRange(pszStr, k + 1, m);  
                Swap(pszStr + k, pszStr + i);  
            }  
        }  
    }  
}  
void Foo(char *pszStr)  
{  
    AllRange(pszStr, 0, strlen(pszStr) - 1);  
}  
int main()  
{  
    printf("         ȥ��ȫ���еĵݹ�ʵ��\n");  
    printf("  --by MoreWindows( http://blog.csdn.net/MoreWindows )--\n\n");  
    char szTextStr[] = "122";  
    printf("%s��ȫ��������:\n", szTextStr);  
    Foo(szTextStr);  
    return 0;  
} 
