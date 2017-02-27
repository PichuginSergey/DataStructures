#ifndef NODE_H_
#define NODE_H_

namespace DataStruct {

	template <typename T>
	struct Node {
		typedef T value_type;
		value_type data_{ value_type() };
		Node* next_{ nullptr };
		Node() {}
		Node(const value_type& data, Node* next = nullptr) : data_(data), next_(next) {}
	};

};

#endif