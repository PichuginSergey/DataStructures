#ifndef STACK_H_
#define STACK_H_

namespace DateStruct {

	template <typename T>
	class Stack {
	public:
		typedef T value_type;
		virtual void push(const value_type& elm) = 0;
		virtual void pop() = 0;
		virtual value_type& top() = 0;
		virtual const value_type& top() const = 0;
		virtual bool isEmpty() const = 0;
		virtual ~Stack() {}
	};
};
#endif