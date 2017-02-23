#ifndef LIST_H_
#define LIST_H_

namespace DataStruct {

	template<typename T>
	class LinkedList {
		
	public:
		typedef T value_type;
		struct Node {
			value_type data_{ value_type() };
			Node* next_{ nullptr };
			Node() {}
			Node(const value_type& data, Node* next = nullptr) : data_(data), next_(next) {}
		};

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
		Node* find(const value_type& data) const;
		bool remove(const value_type& data);
		void swap(LinkedList& list);

	private:
		void deleteList();
		Node* head_{ nullptr };
		size_t size_ {0};
	};

	template <typename T>
	LinkedList<T>::~LinkedList() {
		deleteList();	
	}
	
	template <typename T>
	void LinkedList<T>::deleteList() {
		Node* tmp = head_;
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
	size_t LinkedList<T>::size() const {
		return size_;
	}

	template <typename T>
	void LinkedList<T>::push_front(const value_type& data) {
		head_ = new Node(data, head_);
		++size_;
	}

	template <typename T>
	typename LinkedList<T>::value_type LinkedList<T>::pop_front() {
		Node* curNode = head_;
		value_type tmpElm = head_->data_;
		head_ = head_->next_;
		delete curNode;
		return tmpElm;
	}

	template <typename T>
	LinkedList<T>::LinkedList(const LinkedList& list) {
		Node tmpNode;
		Node* cur = &tmpNode;
		Node* curCopy = list.head_;
		for (size_t size = 0; size != list.size(); ++size) {
			cur->next_ = new Node(curCopy->data_);
			curCopy = curCopy->next_;
			cur = cur->next_;
		}
		size_ = list.size();
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

		Node tmpNode;
		Node* cur = &tmpNode;
		for (const auto& elm : init_list) {
			cur->next_ = new Node(elm);
			cur = cur->next_;
			++size_;
		}
		head_ = tmpNode.next_;
	}

	template <typename T>
	void LinkedList<T>::swap(LinkedList& list) {
		std::swap(this->head_, list.head_);
		std::swap(this->size_, list.size_);
	}

	template<typename T>
	void LinkedList<T>::sortedInsert(const value_type& data) {
		Node tmp;
		tmp.next_ = head_;
		Node* cur = &tmp;
		while(cur->next_ != nullptr && cur->next_->data_ < data)
			cur = cur->next_;
		Node* newNode = new Node(data, cur->next_);
		cur->next_ = newNode;
		head_ = tmp.next_;
		++size_;
	}
	
	template <typename T>
	typename LinkedList<T>::Node* LinkedList<T>::find(const value_type& data) const {
		Node* curNode = head_;
		while(curNode != nullptr && curNode->data_ != data)
			curNode = curNode->next_;
		return curNode;
	}

	template <typename T>
	bool LinkedList<T>::remove(const value_type& data) {
	
		Node tmp;
		tmp.next_ = head_;
		Node* cur = &tmp;
		while(cur->next_ != nullptr && cur->next_->data_ != data)
			cur = cur->next_;
		if (cur->next_ == nullptr || cur->next_->data_ != data)
			return false;
		Node* deleteNode = cur->next_;
		cur->next_ = deleteNode->next_;
		delete deleteNode;
		head_ = tmp.next_;
		--size_;
		return true;
	}

	template <typename T>
	void LinkedList<T>::display() {
		for (Node* tmp = head_; tmp; tmp = tmp->next_)
			std::cout << tmp->data_ << ' ';
		std::cout << std::endl;
	}
};


#endif