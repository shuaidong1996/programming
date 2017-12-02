#include<iostream>  
using namespace std;  
//copy�Ĵ��룬��δ���� 
  
void merge(int* a, int* temp, int begin, int middle, int end){  
    int i = begin;  
    int j = middle + 1;  
    int k = 0;  
    while (i <= middle&&j <= end){//�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��  
        if (a[i] < a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
    while (i <= middle)//����һ��������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β  
        temp[k++] = a[i++];  
    while (j <= end)//���ڶ���������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β  
        temp[k++] = a[j++];  
    for (i = 0; i < k; i++)//������õ����п�����������  
        a[begin + i] = temp[i];  
}  
//�ݹ�汾  
void merge_sort_recurse(int* a, int* temp, int begin, int end){  
    int middle = (begin + end) >> 1;  
    if (begin < end){  
        merge_sort_recurse(a, temp, begin, middle);//�������  
        merge_sort_recurse(a, temp, middle + 1, end);//�ұ�����  
        merge(a, temp, begin, middle, end);//�ٽ������������кϲ�  
    }  
}  
//�ǵݹ�汾����a�����ڳ���Ϊs�������������鲢  
void merge_pass(int* a, int* temp, int s, int len){  
    int i = 0;  
    int j;  
    while (i < len - 2 * s + 1){  
        merge(a, temp, i, i + s - 1, i + 2 * s - 1);  
        i += 2 * s;  
    }  
    if (i < len - s + 1)//�鲢�����������  
        merge(a, temp, i, i + s - 1, len);   
}  
void merge_sort_no_recurse(int* a, int len){  
    int temp[1001];  
    int k = 1;  
    while (k <= len){  
        merge_pass(a, temp, k, len);  
        k *= 2; //�����г��ȼӱ�  
    }  
}  
  
int main(){  
    int num1[1001] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };  
    int temp1[1001];  
    int num2[1001] = { 50, 10, 90, 30, 70, 40, 80, 60, 20 };  
    int n = 9;  
  
    merge_sort_recurse(num1, temp1, 0, n-1);  
    for (int i = 0; i < n; i++)  
        cout << num1[i] << " ";  
    cout << endl;  
  
    merge_sort_no_recurse(num2, n - 1);  
    for (int i = 0; i < n; i++)  
        cout << num2[i] << " ";  
    cout << endl;  
      
    return 0;  
}
