#include <iostream>
#include <vector>
using namespace std;


//简化版小顶堆优先级队列实现
class SimpleMinPQ{
private:  // ✅ C++中class默认是private，但明确写出更清晰
	//底层用数组实现二叉堆
	vector<int> heap;

	//堆中元素数量
	int size;

	//父节点的索引（从0开始）
	static int parent(int node){
		int parent = (node-1)/2;//取整//[1,2,4,5,6,8]自己联想下
		return parent;
	}

	//左子节点的索引
	static int left(int node){
		int left = node*2 + 1;
		return left;
	}

	//右子节点的索引
	static int right(int node){
		int right = node*2 + 2;
		return right;
	}

	//上浮操作,时间复杂度是树高O(logN)
	void swim(int node){
		//上浮条件循环,对于小顶堆
		while(node >0 && heap[parent(node)] > heap[node]){
			//值交换
			swap(parent(node),node);
			//记得更新这个上浮节点的新索引
			node = parent(node);

		} 
	}

	//下沉操作
	void sink(int node){
		//下沉终止条件判定
		while(left(node) < size || right(node) < size){
            //比较自己和左右节点看看谁小
            int min = node;
			//分类讨论
			if(left(node) < size && heap[min] > heap[left(node)]){
				min = left(node);//更新索引
			}
			if(right(node) < size && heap[min] > heap[right(node)]){
				min = right(node);//更新索引
			}
			//如果发现左右都比当前大，无需下沉
			if(min == node){
				break;
			}
            //如果发现左右有比当前小的，就交换，即此时min经过上边不再等于node
            swap(min,node);
            node = min;//更新索引
		}
		
	}


	void swap(int i, int j){
		int temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}


	//公共方法
	public:
		//构造函数
		SimpleMinPQ(int capacity) : size(0){//使用初始化列表
			heap.resize(capacity);//使用vector的resize方法
		}
        //vector会自动管理内存，不用写析构函数
		// ~SimpleMinPQ(){
		// 	delete(heap);
		// }
		//返回堆元素数量,思考const加在这里的意义
		int getSize() const{
			return size;
		}

		//查，返回堆顶元素,O(1)
		int peek() const{
			return heap[0];
		}

		//增,向堆中添加元素,复杂度O(logN)
		void push(int x){
			//先加在队尾
			heap[size] = x;
			swim(size);
			size++;
		}

		//删,删除堆顶元素
		int pop(){
			int remove = heap[0];
			//交换到底部
			swap(0,size-1);
			//删除底部
			size--;//思考是否内存泄漏
			//让新队首元素下沉
			sink(0);
			return remove;
		}

};

int main(){
    SimpleMinPQ pq(5);
    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(5);
    pq.push(4);

    cout << pq.pop() << endl; // 1
    cout << pq.pop() << endl; // 2
    cout << pq.pop() << endl; // 3
    cout << pq.pop() << endl; // 4
    cout << pq.pop() << endl; // 5

    return 0;
}
