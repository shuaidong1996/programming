#include <iostream>
using namespace std;

//�������������飬���鳤�ȶ�Ϊn�����ַ����n��n+1����� --- ����д�ˣ����������� 
int BinarySearch(int* arr1, int* arr2, int n){
	if(!arr1 || !arr2 || n < 1)
		return -1;
	int start1, start2, mid1, mid2, end1, end2, max1, max2;
	start1 = start2 = 0;
	end1 = end2 = n - 1;
	while(1){
		mid1 = (end1 + start1) / 2;
		mid2 = (end2 + start2) / 2;
		if(arr1[mid1] == arr2[mid2]){
			max1 = max2 = arr1[mid1];
			break;
		}
		else if(arr1[mid1] < arr2[mid2]){
			if((start1 + end1) & 1 == 0){
				//֮��ĸ���Ϊ����
				start1 = mid1;
			}
			else{
				start1 = mid1 + 1;
			} 
			end2 = mid2;		
			max1 = arr1[mid1];
			max2 = arr2[mid2];
		}
		else{
			if((start1 + end1) & 1 == 0){
				start2 = mid2;
			}
			else{
				start1 = mid1 + 1;
			} 
			end1 = mid1;
			max1 = arr2[mid2];
			max2 = arr1[mid1];
		}
		if(mid1 == 0 || mid2 == 0 || mid1 == n || mid2 == n)
			break;
	}
	cout << max1 << " " << max2 << endl;
	return 0;
}
void test(){
	int arr1[]{1, 2, 3, 4, 5};
	int arr2[]{6, 7, 8, 9, 10};
	BinarySearch(arr1, arr2, 5);
	
	int arr3[]{1, 6, 8};
	int arr4[]{0, 9, 10};
	BinarySearch(arr3, arr4, 3);
}
int main(){
	test();
}
