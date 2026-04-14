#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &nums)
{

	int size = nums.size();
	int sortedIndex = 0;

	//维护[0,sortedIndex)是有序数组
	while(sortedIndex < size)
	{
		for(int i = sortedIndex; i>0; i--){
			//假如从sortedIndex逆序开始，
			//这个新加入元素开始比已排序好【0...sortedIndex】中元素还小了
			if(nums[i] < nums[i-1]){
				int temp = nums[i];
				nums[i] = nums[i-1];
				nums[i-1] = temp;
			}
			//如果新探索的sortedIndex元素比以排序好的元素大
			//就提前终止
			else{
				break;
			}
		}
		sortedIndex++;
	}


}
