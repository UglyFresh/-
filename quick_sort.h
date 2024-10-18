#pragma once
#include "validation.h"

class QuickSort {
	public: 
	/// <summary>
	/// Алгоритм быстрой сортировки
	/// </summary>
	/// <param name="array"></param>
	/// <param name="begin"></param>
	/// <param name="end"></param>
	void Alghoritm(std::vector <int>&array, size_t begin, size_t end) {

		int pivot = array[static_cast<size_t>((begin + end) / 2)];

		size_t start = begin;
		size_t finish = end;
		// O(N * log N)
		do {
			//O(N)
			while (array[start] < pivot) {
				start++;
			}
			//O(N)
			while (array[finish] > pivot) {
				finish--;
			}

			//O(1)
			if (start <= finish) {
				std::swap(array[start], array[finish]);
				start++;
				finish--;
			}
		// O(log N)
		} while (start <= finish);

		//O(log N)
		if (begin < finish) {
			Alghoritm(array, begin, finish);
		}
		//O(log N)
		if (start < end) {
			Alghoritm(array, start, end);
		}

	}
};
