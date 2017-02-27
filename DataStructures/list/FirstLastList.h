#ifndef FIRST_LAST_LIST_H_
#define FIRST_LAST_LIST_H_

#include "Node.h"

namespace DataStruct {

	template <typename T>
	class FirstLastList {

	public:
		typedef T value_type;

		FirstLastList() {}
		FirstLastList(std::initializer_list<T> init_list);
		~FirstLastList();
		FirstLastList(const FirstLastList&);
		FirstLastList& operator=(const FirstLastList&);
		bool isEmpty() const;
		void push_front(const value_type& data);
		void push_back(const value_type& data);
		value_type pop_front();
		void display() const;
		Node<value_type>* find(const value_type& data) const;
		void remove(const value_type& data);
		void swap(FirstLastList& list);

	private:
		void deleteList();
		Node<T>* first_{ nullptr };
		Node<T>* last_{ nullptr };
	};

	template <typename T>
	FirstLastList<T>::FirstLastList(std::initializer_list<T> init_list) {

		Node<value_type> tmpNode;
		auto* cur = &tmpNode;
		auto* prev = cur;
		for (const auto& elm : init_list) {
			cur->next_ = new Node<value_type>(elm);
			prev = cur->next_;
			cur = cur->next_;
		}
		first_ = tmpNode.next_;
		last_ = init_list.size() == 1 ? first_ : prev;
	}

	template <typename T>
	FirstLastList<T>::~FirstLastList() {
		deleteList();
	}

	template <typename T>
	void FirstLastList<T>::deleteList() {
		auto* tmp = first_;
		while (first_) {
			tmp = first_->next_;
			delete first_;
			first_ = tmp;
		}
		last_ = nullptr;
	}

	template <typename T>
	FirstLastList<T>::FirstLastList(const FirstLastList& list) {
		Node<value_type> tmpNode;
		auto* cur = &tmpNode;
		auto* prev = cur;
		for (auto* curCopy = list.head_; curCopy != nullptr; cur = cur->next_) {
			cur->next_ = new Node<T>(curCopy->data_);
			prev = cur->next_;
			curCopy = curCopy->next_;
		}
		first_ = tmpNode.next_;
		last_ = init_list.size() == 1 ? first_ : prev;
	}

	template <typename T>
	FirstLastList<T>& FirstLastList<T>::operator =(const FirstLastList& list) {

		if (this == &list)
			return *this;
		LinkedList<value_type> tmpList(list);
		this->swap(tmpList);
		return *this;
	}

	template <typename T>
	bool FirstLastList<T>::isEmpty() const { return first_ == nullptr };

	template <typename T>
	void FirstLastList<T>::push_front(const value_type& data) {

		first_ = new Node<value_type>(data, first_);
		if (last_ == nullptr)
			last_ = first_;
	}

	template <typename T>
	void FirstLastList<T>::push_back(const value_type& data) {

		auto* newElm = new Node<T>(data, nullptr);
		if (first_ == nullptr) {
			last_ = newElm;
			first_ = newElm;
		}
		else {
			last_->next_ = newElm;
			last_ = newElm;
		}
	}

	template <typename T>
	typename  FirstLastList<T>::value_type FirstLastList<T>::pop_front() {
		auto* tmp = first_;
		auto tmpElm = tmp->data_;
		first_ = first_->next_;
		if (first_->next_ == nullptr)
			last_ = first_;
		delete tmp;
		return tmpElm;
	}

	template <typename T>
	void FirstLastList<T>::display() const {
		auto* tmp = first_;
		while (tmp != nullptr) {
			std::cout << tmp->data_ << ' ';
			tmp = tmp->next_;
		}
		std::cout << std::endl;
	}

	template <typename T>
	Node<T>* FirstLastList<T>::find(const value_type& data) const {

		auto* tmp = first_;
		while (tmp != nullptr) {
			if (tmp->data_ == data)
				break;
			tmp = tmp->next_;
		}
		return tmp;
	}

	template <typename T>
	void FirstLastList<T>::remove(const value_type& data) {

		if (first_ == nullptr)
			return;
		
		if (first_->data_ == data) {
			auto* del = first_;
			if (first_ == last_)
				last_ = nullptr;
			first_ = first_->next_;
			delete del;
			return;
		}
		else {
			auto* tmp = first_;
			while (tmp->next_ != NULL) {
				if (tmp->next_->data_ == data) {
					auto* del = tmp->next_;
					if (tmp->next_ == last_)
						last_ = tmp;
					tmp->next_ = tmp->next_->next_;
					delete del;
					return;
				}
				tmp = tmp->next_;
			}
		}
	}

	template <typename T>
	void FirstLastList<T>::swap(FirstLastList& list) {
		std::swap(this->first_, list.first_);
		std::swap(this->last_, list.last_);
	}

};

#endif