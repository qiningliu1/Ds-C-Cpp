#include <iostream>
#include <vector>
using namespace std;
#define MIN_NUM INT_MAX

void sort(vector<int> &nums)
//思考这里传参与(vector<int> *nums区别)
{

	int size = nums.size();
	int i = 0;
	while (i<size){
		//假设当前位置最小
		int minIndex = i;
		for (int j = i+1;j<size;j++){
			if(nums[minIndex] > nums[j]){
				minIndex = j;
			}
		}
		//进行交换
		if(minIndex != i){
			int temp = nums[minIndex];
			nums[minIndex] = nums[i];
			nums[i] = temp;
		}
		i++;
	}

}

void printArray(const vector<int>& nums) {
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {
    vector<int> nums = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "排序前: ";
    printArray(nums);
    
    sort(nums);
    
    cout << "排序后: ";
    printArray(nums);
    
    return 0;
}

