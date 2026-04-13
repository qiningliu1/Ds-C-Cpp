#include <iostream>
#include "list.hpp"

int main(void)
{
    myArrayList list1;
    list1.addLast(1);
    list1.addLast(2);
    list1.addLast(3);
    list1.addLast(4);
    list1.addLast(5);
    list1.print();
    list1.removeFirst();
    list1.print();
    list1.removeLast();
    list1.print();
    list1.removeIndex(1);
    list1.print();
    list1.set(1,100);
    
    myArrayList list2(10);
    list2.print();
    list2.addLast(1);
    list2.addLast(2);
    list2.addLast(3);
    list2.addLast(4);
    list2.addLast(5);
    list2.print();
    
    
    
    return 0;
}