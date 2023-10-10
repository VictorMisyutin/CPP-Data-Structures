#ifndef STACK_H
#define STACK_H
class FullStack{};
class EmptyStack{};
struct NodeType;
typedef int ItemType;
class StackType{
	public:
		StackType();
		~StackType();
		void Push(ItemType);
		void Pop();
		void Print();
		ItemType Top();
		bool IsEmpty() const;
		bool IsFull() const;
	private:
		NodeType* topPtr;
};
#endif
