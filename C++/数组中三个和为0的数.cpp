#include <iostream>
#include <vector> 
#include <algorithm>
#include <bitset>
using namespace std;
void printVVI(vector<vector<int>> vv){
	auto vvit = vv.begin();
	while(vvit != vv.end()){
		auto vit = (*vvit).begin();
		while(vit != (*vvit).end()){
			cout << *vit++ << " ";
		}
		vvit++; 
		cout << endl;
	}
}
/* 
���������ĺ�ΪN������ (1)������ǰ��ָ�롣O(NlogN) (2)hash Ȼ�� ����һ�� O(N) ȱ�㣺������Ҫ�󣬺��ڴ�
���������ĺ�(1)������ָ��һ������������������������ķ���ʵ�֡�O(N^2)  ����Ҫ���ظ�����Ҫ�������㷨�޸� 
���ĸ���Ӧ��Ҳ���ԣ�����ʱ�临�ӶȾ���O(N^3) ��Խ�ิ�Ӷ�Խ�� �������ַ������Ǻܺ� ---- ����Ҳ���Լ���˼· 
 */ 
//start end ��Ϊ�˶��ֵ�ʱ��ȥǰ����� Ŀ��Ϊ�˲��ظ� 
vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target){
    int i = start, j = end;
    vector<vector<int>> res;
    while(i < j){
        if(nums[i] + nums[j] == target){
            vector<int> v;
            v.push_back(nums[i]);
            v.push_back(nums[j]);
            res.push_back(v);
            while(nums[i] == nums[++i]);//����Ҫ���ظ���ȥ��ǰ��ͺ�����ͬ���� 
            while(nums[j] == nums[--j]);
        }
        else if(nums[i] + nums[j] < target){
            ++i;
        }
        else{
            --j;
        }
    }
    return res;
}
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
    int size = nums.size();
    int temp;
    vector<vector<int>> res;
    for(int i = 0; i < size - 2; ++i){
    	if(i - 1 >= 0 && nums[i] == nums[i - 1])//���ڲ��ظ���ȥ��������ͬ���� 
    		continue;
        temp = 0 - nums[i];//��Ϊ0  ͬ���ΪNҲ���� 
        vector<vector<int>> tempRes = twoSum(nums, i + 1, size - 1, temp);
        int tempSize = tempRes.size();
        for(int j = 0; j < tempSize; ++j){
            tempRes[j].push_back(nums[i]);
            res.push_back(tempRes[j]);
        }
    }
    return res;
}

int main1(){
	vector<int> inV{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	printVVI(threeSum(inV));
}
/*
Ѱ�Һ�Ϊ��ֵ����������
*/
int res[100], k = 0;
void sumOfKNumber(int *a, int n, int sum){
    if(n <= 0 || sum <= 0)
        return;
    if(k > 0){
        if(sum == a[n-1]){
            for(int i = k-1; i >= 0; --i)
                cout << res[i] << ",";
            cout << a[n-1]  << endl; //�ر�ע�⣬���ʱ����Ԫ�ػ�δ��������
        }
    }
    //�����Ƿ�ȡ��n����
    res[k++] = a[n-1];
    sumOfKNumber(a, n-1, sum-a[n-1]);
    k--;
    sumOfKNumber(a, n-1, sum);
}
int main(){
    int a[100]{-1,0,1,2,-1,-4}, n = 6, ans = 2;
    sumOfKNumber(a, n, ans);
    return 0;
}
