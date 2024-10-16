#pragma once
#include "validation.h"

class QuickSort {
	public: 
	QuickSort(std::vector<int> arr, int b, int e) : array(arr), begin(b), end(e){}
	~QuickSort() {}

	//Функция сортировки
	static void Sort(std::vector <int>& array, int begin, int end) {

		int pivot = array[(begin + end) / 2];

		int start = begin;
		int finish = end;
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
			Sort(array, begin, finish);
		}
		//O(log N)
		if (start < end) {
			Sort(array, start, end);
		}

	}

private:

	std::vector <int> array;
	int begin, end;

};
