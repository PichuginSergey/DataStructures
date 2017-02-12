#ifndef DYNAMIC_ARRAY_STACK_H_
#define DYNAMIC_ARRAY_STACK_H_

#include "stack.h"

namespace DateStruct {

	template <typename T>
	class DynamicArrayStack : public Stack<T> {

	public:
		typedef size_t size_type;
		explicit DynamicArrayStack(size_type size = DEFAULT_STACK_SIZE) : capacity_(size),
			size_(0), data_(new value_type[size]) {}
		~DynamicArrayStack() override {
			delete[] data_;
		}
		DynamicArrayStack(const DynamicArrayStack& stack);
		DynamicArrayStack& operator=(const DynamicArrayStack& lhv);
		void swap(DynamicArrayStack& lhv);
		void push(const value_type& elm) override;
		void pop() override;
		value_type& top() override;
		const value_type& top() const override;
		bool isEmpty() const override;

	private:
		void resize(size_type capacity);
		size_type capacity_;
		size_type size_;
		T* data_;
		enum { RESIZE_FACTOR = 2, DEFAULT_STACK_SIZE = 5};
	};

	template<typename T>
	bool DynamicArrayStack<T>::isEmpty() const {
		return size_ == 0;
	}

	template<typename T>
	DynamicArrayStack<T>::DynamicArrayStack(const DynamicArrayStack<T>& stack) :
		capacity_(stack.capacity_), size_(stack.size_), data_(new value_type[size_]) {
		for (size_t i = 0; i < size_; ++i)
			data_[i] = stack.data_[i];
	}

	template<typename T>
	DynamicArrayStack<T>& DynamicArrayStack<T>::operator=(const DynamicArrayStack<T>& lhs) {
		if (this == &lhs)
			return *this;
		DynamicArrayStack tmpStack(lhs);
		tmpStack.swap(*this);
		return *this;
	}

	template<typename T>
	void DynamicArrayStack<T>::swap(DynamicArrayStack& lhv) {
		std::swap(data_, lhv.data_);
		std::swap(size_, lhv.size_);
		std::swap(capacity_, lhv.capacity_);
	}

	template<typename T>
	auto DynamicArrayStack<T>::top() const -> const value_type& {
		return data_[size_ - 1];
	}

	template<typename T>
	auto DynamicArrayStack<T>::top() -> value_type& {
		return data_[size_ - 1];
	}

	template<typename T>
	void DynamicArrayStack<T>::push(const value_type& val) {

		if (size_ == capacity_)
			resize(RESIZE_FACTOR * capacity_);
		data_[size_++] = val;
	}

	template<typename T>
	void DynamicArrayStack<T>::pop() {
		--size_;
		if (size_ <= capacity_ / RESIZE_FACTOR && size_ >= DEFAULT_STACK_SIZE)
			resize(capacity_ / RESIZE_FACTOR);
	}

	template<typename T>
	void DynamicArrayStack<T>::resize(size_type capacity) {
		capacity_ = capacity;
		value_type* deleteData = data_;
		data_ = new value_type[capacity_];
		for (size_t i = 0; i < size_; ++i)
			data_[i] = deleteData[i];
		delete[] deleteData;
	}

};
#endif