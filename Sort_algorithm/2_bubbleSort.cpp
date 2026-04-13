#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int> &nums)
{

	int size = nums.size();
	int sortedIndex = 0;
	while (sortedIndex<size){
		
		//我们需要在这一轮交换中找到这一轮最小值放到sortedIndex
		//需要找的过程中在一个循环里就完成交换数据，避免后续再整体位置移动
		//为了同时实现排序稳定，避免改变相对位置顺序如1和1'和1''位置改变，我们从逆序(默认相对位置排好了)，一个挨一个交换
		
        //优化
        bool isSorted = false;
        //逆序遍历，找到逆序对，交换
        for (int j = size-1;j>sortedIndex;j--){
			
            if(nums[j] < nums[j-1]){
				//swap
				int temp = nums[j];
				nums[j] = nums[j-1];
				nums[j-1] = temp;
                isSorted = true;
			}
		}
        // 如果一次交换操作都没有进行，说明数组已经有序，可以提前终止算法
        if(!isSorted){
            break;
        }

		sortedIndex++;
	}

}

