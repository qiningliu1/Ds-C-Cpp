#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>

class Node {
public:
	int val;
	std::vector<Node*> children;

	//构造函数
	//只初始化值
	Node(int x): val(x){}

	//初始化值并添加一个节点
	Node(int x,Node* child): val(x){
		if(child!=nullptr){
			children.push_back(child);
		}
	}

	//析构函数
	~Node(){
		for(Node* child : children){
			delete child;
		}
	}

	//添加子节点的方法
	void addChild(Node* child){
		if(child!=nullptr){
			children.push_back(child);
		}
	}

	//添加多个子节点
	void addChildren(const vector<Node*> &newChildren){
		for(Node* child : newChildren){
			if(child!=nullptr){
				children.push_back(child);
			}
		}
	}


};

//多叉树DFS遍历
void traverse(Node* root)
{
	if(root == nullptr)
	{
		return;
	}
	//前序位置：处理当前节点
	std::cout<<"访问节点: "<< root->val <<std::endl;

	for(Node* child : root->children){
		traverse(child);
	}

	//后序位置: 子节点处理完后的操作
	std::cout<<"离开节点: "<< root->val << std::endl;
}

//多叉树的层序遍历,无深度只是遍历
void bfs_traversal(Node* root)
{
	if(root==nullptr)
	{
		return;
	}
	//初始化队列
	std::queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* current = q.front();
		//出栈
		q.pop();
		//访问子节点
		//把子节点入栈，注意这里和层数无关，只是给队列添加元素
		for(Node* child : current->children){
			q.push(child);
		}

	}
}

//记录深度，与上边对比，每一层结束遍历都会打印当前层，但是遍历顺序和上边一样
void bfs_depth(Node* root)
{
	if(root==nullptr)
	{
		return;
	}
	//队列
	std::queue<Node*> q;
	q.push(root);
	//记录当前层数
	int depth = 1;
	while(!q.empty())
	{
		int levelSize = q.size();
		for(int i = 0; i<levelSize;i++){
			Node* current = q.front();
			q.pop();
			//记录此时位置
			std::cout<<"depth= "<<depth<<", val= "<<current->val<<std::endl;
			//入栈，准备下层便利
			for(Node* child:current->children){
				q.push(child);
			}
		}
		depth++;
	}
}