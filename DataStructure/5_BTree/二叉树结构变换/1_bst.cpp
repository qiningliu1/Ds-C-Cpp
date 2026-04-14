#include <iostream>

template<typename K, typename V>
class TreeNode
{
    public:
        K key;
        V value;
        TreeNode<K,V>* left;
        TreeNode<K,V>* right;
        TreeNode(K k, V v): key(k), value(v), left(nullptr), right(nullptr){}
};