#include <iostream>
using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int val):val(val),next(nullptr){}//成员变量val = 参数val
};

class Solution{
public:
	ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
		// ListNode dummy = new ListNode(-1);//注意new关键字是返回指针，所以这里语法错误
        ListNode dummy(-1);
		ListNode* p = &dummy;//思考这里写入dummy地址还是dummy->next合适
		

		//开始构造，遍历
        //这里直接用list1和list2，在我们这个函数内它们会复制传参(值传递)，所以不会影响原链表
		while(list1 != nullptr && list2 !=nullptr){//NUll和nullptr区别是什么，nullptr是C++11引入的，NULL是C语言的宏定义
			if(list1->val > list2->val){
				p->next = list2;
				list2 = list2->next;//往后移动
			}
			else{
				p->next = list1;
				list1 = list1->next;
			}
			p = p->next;//p遍历指针向后移动准备下一轮合成
		}
		//假如有一条链表到头
		if(list1 != NULL){
			p->next = list1;
		}
		if(list2 != NULL){
            p->next = list2;
        }
		return dummy.next;
	}
};


// ... existing code ...

int main() {
    Solution solution;
    
    // 创建测试链表1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    
    // 创建测试链表2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    
    // 合并两个链表
    ListNode* merged = solution.mergeTwoLists(list1, list2);
    
    // 打印结果
    cout << "合并后的链表: ";
    ListNode* current = merged;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
    
    // 清理内存
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }
    
    return 0;
}

