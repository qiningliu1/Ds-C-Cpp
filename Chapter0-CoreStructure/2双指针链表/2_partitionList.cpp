#include <iostream>
using namespace std;

struct ListNode{
	struct ListNode* next;
	int val;
	ListNode(int val):val(val),next(nullptr){};
};

class Solution{
public:
	ListNode* partition(ListNode* head, int x){
		ListNode* small = new ListNode(-1);//这里一开始定义的结构体可否用new
		ListNode* large = new ListNode(-1);
		ListNode* p1 = small, *p2 = large;//负责生成各自链表
		ListNode* p = head;//遍历指针
		while(p != NULL){
			if(p->val < x){
				//构造小链表
				p1->next = p;
				p1 = p1->next;
			}
			else{
				p2->next = p;
				p2 = p2->next;
			}
//难点，这里如果直接移动p会出现环
//需要一节节分解原链表，一节节构建两个新的分解链表
//如果整段搬移着安装容易使最后节点没能及时断开，形成环

			ListNode* temp = p->next;//暂存下一节点的地址
			p->next = nullptr;//让当前节点的next指针断开，不记录原来的下一个节点位置
			//delete p->next;这个会造成悬空指针直接释放内存
			p = temp;//往前移动
		}
		//构造新链表
        //最好断开large链表尾部
        p2->next = nullptr;
		p1->next = large->next;
        //堆上内存释放
        //先储存结果
        ListNode* result = small->next;
        //释放虚拟节点占用内存
        delete small;
        delete large;
		return result;
	}	
};