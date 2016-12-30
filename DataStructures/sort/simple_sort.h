#ifndef SIMPLE_SORT_H_
#define SIMPLE_SORT_H_

namespace simpleSort {

	template <typename T>
	void bubbleSort(T data[], size_t size) {

		if (size <= 1) return;

		for (size_t out = 0; out < size - 1; ++out)
			for (size_t in = 1; in < size - out; ++in)
				if (data[in - 1] > data[in])
					std::swap(data[in - 1], data[in]);
	}

	template <typename T>
	void selectSort(T data[], size_t size) {

		if (size <= 1) return;

		for (size_t out = 0; out < size - 1; ++out) {
			size_t min_idx = out;
			for (size_t in = out + 1; in < size; ++in)
				if (data[in] < data[min_idx])
					min_idx = in;
			std::swap(data[out], data[min_idx]);
		}
	}

	template <typename T>
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