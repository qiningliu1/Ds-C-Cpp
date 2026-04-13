/**
只遍历一次就找到单链表的倒数第k个节点
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int val):val(val), next(nullptr){}
};

class Solution{
public:
    ListNode* findFromEnd(ListNode* head,int k){
	ListNode* p1 = head;
	//p1先走k步
	for(int i = 0; i<k; i++){
		p1 = p1->next;
	}
	ListNode* p2 = head;
	while(p1!=NULL){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

};


// 创建链表的辅助函数
ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    
    for (int i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    
    return head;
}

// 打印链表的辅助函数
void printList(ListNode* head) {
    cout << "链表: ";
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// 释放链表内存的辅助函数
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution solution;
    
    // 测试案例1: 正常情况
    cout << "=== 测试案例1: 正常情况 ===" << endl;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(nums1);
    printList(head1);
    
    int k1 = 2;
    cout << "查找倒数第" << k1 << "个节点" << endl;
    ListNode* result1 = solution.findFromEnd(head1, k1);
    if (result1) {
        cout << "结果: " << result1->val << endl;
    } else {
        cout << "结果: 未找到" << endl;
    }
    cout << endl;
    
    // 测试案例2: k=1 (最后一个节点)
    cout << "=== 测试案例2: k=1 ===" << endl;
    ListNode* head2 = createList({1, 2, 3, 4, 5});
    printList(head2);
    
    int k2 = 1;
    cout << "查找倒数第" << k2 << "个节点" << endl;
    ListNode* result2 = solution.findFromEnd(head2, k2);
    if (result2) {
        cout << "结果: " << result2->val << endl;
    } else {
        cout << "结果: 未找到" << endl;
    }
    cout << endl;
    
    // 测试案例3: k等于链表长度 (第一个节点)
    cout << "=== 测试案例3: k等于链表长度 ===" << endl;
    ListNode* head3 = createList({1, 2, 3, 4, 5});
    printList(head3);
    
    int k3 = 5;
    cout << "查找倒数第" << k3 << "个节点" << endl;
    ListNode* result3 = solution.findFromEnd(head3, k3);
    if (result3) {
        cout << "结果: " << result3->val << endl;
    } else {
        cout << "结果: 未找到" << endl;
    }
    cout << endl;
    
    // 测试案例4: k大于链表长度
    cout << "=== 测试案例4: k大于链表长度 ===" << endl;
    ListNode* head4 = createList({1, 2, 3});
    printList(head4);
    
    int k4 = 5;
    cout << "查找倒数第" << k4 << "个节点" << endl;
    ListNode* result4 = solution.findFromEnd(head4, k4);
    if (result4) {
        cout << "结果: " << result4->val << endl;
    } else {
        cout << "结果: 未找到" << endl;
    }
    cout << endl;
    
    // 测试案例5: 空链表
    cout << "=== 测试案例5: 空链表 ===" << endl;
    ListNode* head5 = nullptr;
    cout << "链表: 空" << endl;
    
    int k5 = 1;
    cout << "查找倒数第" << k5 << "个节点" << endl;
    ListNode* result5 = solution.findFromEnd(head5, k5);
    if (result5) {
        cout << "结果: " << result5->val << endl;
    } else {
        cout << "结果: 未找到" << endl;
    }
    cout << endl;
    
    // 清理内存
    deleteList(head1);
    deleteList(head2);
    deleteList(head3);
    deleteList(head4);
    
    return 0;
}
