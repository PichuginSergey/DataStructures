#ifndef LINK_LIST_STACK_H_
#define LINK_LIST_STACK_H_

#include "stack.h"

namespace DateStruct {

	template <typename T>
	class LinkListStack : public Stack<T> {

	public:

		LinkListStack() : stack_(nullptr) {}
		~LinkListStack() override {
			deleteStack();
		}
		LinkListStack(const LinkListStack& stack);
		LinkListStack& operator=(const LinkListStack& stack);
		void swap(LinkListStack<T>& rhv);
		void push(const value_type& elm) override;
		void pop() override;
		value_type& top() override;
		const value_type& top() const override;
		bool isEmpty() const override;

	private:
		struct LinkElm {
			value_type elm;
			LinkElm* next;
		};

		void deleteStack();

		LinkElm* stack_;
	};

	template<typename T>
	bool LinkListStack<T>::isEmpty() const {
		return stack_ == nullptr;
	}

	template<typename T>
	void LinkListStack<T>::push(const value_type& elm) {
		LinkElm* newElm = new LinkElm;
		newElm->elm = elm;
		newElm->next = stack_;
		stack_ = newElm;
	}

	template<typename T>
	void LinkListStack<T>::pop() {
		LinkElm* tmpLink = stack_->next;
		delete stack_;
		stack_ = tmpLink;
	}

	template<typename T>
	auto LinkListStack<T>::top() const -> const value_type& {
		return stack_->elm;
	}

	template<typename T>
	auto LinkListStack<T>::top() -> value_type& {
		return stack_->elm;
	}

	template<typename T>
	void LinkListStack<T>::deleteStack() {

		LinkElm* tmpLink = stack_;
		while (stack_) {
			stack_ = stack_->next;
			delete tmpLink;
			tmpLink = stack_;
		}
	}

	template<typename T>
	LinkListStack<T>::LinkListStack(const LinkListStack<T>& stack) {
		this->stack_ = nullptr;
		if (stack.isEmpty()) 
			return;
		stack_ = new LinkElm;
		stack_->elm = stack.stack_->elm;
		stack_->next = nullptr;
		LinkElm* tmpLink = stack.stack_->next;
		LinkElm* newElm = stack_;
		while (tmpLink) {
			newElm->next = new LinkElm;
			newElm = newElm->next;
			newElm->elm = tmpLink->elm;
			newElm->next = nullptr;
			tmpLink = tmpLink->next;
		}
	}

	template<typename T>
	LinkListStack<T>& LinkListStack<T>::operator=(const LinkListStack<T>& stack) {
		if (this == &stack)
			return *this;
		LinkListStack<T> tmpStack(stack);
		this->swap(tmpStack);
		return *this;
	}

	template<typename T>
	void LinkListStack<T>::swap(LinkListStack<T>& rhv) {
		std::swap(this->stack_, rhv.stack_);
	}

};
#endif