#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	struct ListNode* next;
	int val;
	ListNode(int val):val(val),next(nullptr){};
};

/**
 * 合并k个有序链表逻辑类似合并两个有序链表
 * 但是需要快速得到k个节点中的最小节点
 * 考虑可以每次(小顶堆弹出最小值)
 * 这样每次可以获得k个节点中的最小节点
 */
class Solution{
public:
	ListNode* mergeKLists(vector<ListNode*> &lists){
		if(lists.empty()) return nullptr;
		//虚拟头节点
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;

		//优先级队列构建
		//这里看不懂cpp的语法，是否需要单独前边封装写好小顶堆数据结构
		auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
		priority_queue<ListNode*, vector<ListNode*>,decltype(cmp)> pq(cmp);

		//将k个链表的头结点加入最小堆
		for(ListNode* head : lists){
			if(head != nullptr) {
				pq.push(head);
			}
		}

		while(!pq.empty()){
			//获取最小节点,接到结果链表
			ListNode* node = pq.top();
			pq.pop();//出栈，组织小顶堆重新排序
			p->next = node;
			if(node->next != nullptr){
				//这里我的理解是当链表头节点从堆中出去后
				//把它的下一个节点压入小顶堆，自发进行重新swim上浮
				pq.push(node->next);
			}
			//p指针前进
			p = p->next;
		}
		return dummy->next;
	}
};
