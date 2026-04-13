#include<iostream>
#include<vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val):val(val),next(nullptr){};
};

class Solution{
public:
bool hasCycle(ListNode* head){

     //这种写法错误，只判断了小环的情况，没有判断大环的情况
    // ListNode* dummy = new ListNode(0);
    // dummy->next = head;

    // ListNode* slow = dummy;
    // ListNode* fast = head;
    // while(fast != nullptr && fast->next != nullptr){

    //     fast = fast->next;
    //     if(fast == slow) return true;
    //     slow = slow->next;
    // }
    // return false;


ListNode* fast = head;
ListNode* slow = head;

while(fast != nullptr && fast->next != nullptr){
    fast = fast->next->next;
    slow = slow->next;
    if(fast == slow) return true;
}
return false;




}

};