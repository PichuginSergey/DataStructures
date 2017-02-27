#ifndef LIST_H_
#define LIST_H_

#include "Node.h"

namespace DataStruct {

	template<typename T>
	class LinkedList {
		
	public:
		typedef T value_type;

		LinkedList() {}
		LinkedList(std::initializer_list<T> init_list);
		~LinkedList();
		LinkedList(const LinkedList&);
		LinkedList& operator=(const LinkedList&);
		bool isEmpty() const;
		size_t size() const;
		void push_front(const value_type& data);
		value_type pop_front();
		void sortedInsert(const value_type& data);
		void display();
		Node<T>* find(const value_type& data) const;
		bool remove(const value_type& data);
		void swap(LinkedList& list);

	private:
		void deleteList();
		Node<T>* head_ {nullptr};
	};

	template <typename T>
	LinkedList<T>::~LinkedList() {
		deleteList();	
	}
	
	template <typename T>
	void LinkedList<T>::deleteList() {
		Node<T>* tmp = head_;
		while(head_) {
			tmp = head_->next_;
			delete head_;
			head_ = tmp;
		}
	}

	template <typename T>
	bool LinkedList<T>::isEmpty() const {
		return head_ == nullptr;
	}

	template <typename T>
	void LinkedList<T>::push_front(const value_type& data) {
		head_ = new Node<T>(data, head_);
	}

	template <typename T>
	typename LinkedList<T>::value_type LinkedList<T>::pop_front() {
		Node<T>* curNode = head_;
		value_type tmpElm = head_->data_;
		head_ = head_->next_;
		delete curNode;
		return tmpElm;
	}

	template <typename T>
	LinkedList<T>::LinkedList(const LinkedList& list) {
		Node<T> tmpNode;
		Node<T>* cur = &tmpNode;
		for (Node<T>* curCopy = list.head_; curCopy != nullptr; cur = cur->next_) {
			cur->next_ = new Node<T>(curCopy->data_);
			curCopy = curCopy->next_;
		}
		head_ = tmpNode.next_;
	}

	template <typename T>
	LinkedList<T>& LinkedList<T>::operator =(const LinkedList& list) {
	
		if (this == &list)
			return *this;
		LinkedList<LinkedList::value_type> tmpList(list);
		this->swap(tmpList);
		return *this;
	}

	template <typename T>
	LinkedList<T>::LinkedList(std::initializer_list<T> init_list) {

		Node<T> tmpNode;
		Node<T>* cur = &tmpNode;
		for (const auto& elm : init_list) {
			cur->next_ = new Node<T>(elm);
			cur = cur->next_;
		}
		head_ = tmpNode.next_;
	}

	template <typename T>
	void LinkedList<T>::swap(LinkedList& list) {
		std::swap(this->head_, list.head_);
	}

	template<typename T>
	void LinkedList<T>::sortedInsert(const value_type& data) {
		Node<T> tmp;
		tmp.next_ = head_;
		Node<T>* cur = &tmp;
		while(cur->next_ != nullptr && cur->next_->data_ < data)
			cur = cur->next_;
		Node<T>* newNode = new Node<T>(data, cur->next_);
		cur->next_ = newNode;
		head_ = tmp.next_;
	}
	
	template <typename T>
	Node<T>* LinkedList<T>::find(const value_type& data) const {
		Node<T>* curNode = head_;
		while(curNode != nullptr && curNode->data_ != data)
			curNode = curNode->next_;
		return curNode;
	}

	template <typename T>
	bool LinkedList<T>::remove(const value_type& data) {
	
		Node<T> tmp;
		tmp.next_ = head_;
		Node<T>* cur = &tmp;
		while(cur->next_ != nullptr && cur->next_->data_ != data)
			cur = cur->next_;
		if (cur->next_ == nullptr || cur->next_->data_ != data)
			return false;
		Node<T>* deleteNode = cur->next_;
		cur->next_ = deleteNode->next_;
		delete deleteNode;
		head_ = tmp.next_;
		return true;
	}

	template <typename T>
	void LinkedList<T>::display() {
		for (auto tmp = head_; tmp; tmp = tmp->next_)
			std::cout << tmp->data_ << ' ';
		std::cout << std::endl;
	}
};


#endif