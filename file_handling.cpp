#include "file_handling.h"

//—охранение отсортированного массива в файл
void FileInput(std::vector<int> array) {

	std::ofstream file("array_after_sort.txt");

	if (!file.is_open()) {
		std::cout << "ќшибка открыти€ файла!\n";
	}
	else {
		for (size_t i = 0; i != array.size(); ++i) {
			file << array[i] << "\t";
		}
	}

	file.close();
}

//—ортировка массива из файла
void FileOutput(std::vector<int>& array) {

	std::ifstream file("array_for_sort.txt");
	std::string line;
	int num = 0;

	if (!file.is_open()) {
		std::cout << "ќшибка открыти€ файла!";
	}
	else {
		while (std::getline(file, line, '\t')) {
			int support{ std::stoi(line) };
			std::cout << "Ёлемент массива [" << num + 1 << "] равен: " << support << "\n";
			array.push_back(support);
			num++;
		}
	}

	file.close();

}