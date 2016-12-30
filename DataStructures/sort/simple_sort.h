#ifndef SIMPLE_SORT_H_
#define SIMPLE_SORT_H_

namespace simpleSort {

	template<typename T>
	void insertSort(T data[], size_t size) {

		if (size <= 1) return;

		for (size_t out = 1; out < size; ++out) {
			size_t in = out;
			T tmp = data[out];
			while (in > 0 && data[in - 1] > tmp) {
				data[in] = data[in - 1];
				--in;
			}
			data[in] = tmp;
		}
	}

}

#endif