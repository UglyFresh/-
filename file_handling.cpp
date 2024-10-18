#include "file_handling.h"


void FileInput(std::vector<int> array) {

	std::ofstream file("array_after_sort.txt");

	if (!file.is_open()) {
		std::cout << "Ошибка открытия файла!\n";
	}
	else {
		for (size_t i = 0; i != array.size(); ++i) {
			file << array[i] << "\t";
		}
	}

	file.close();
}

bool FileOutput(std::vector<int>& array) {

	std::ifstream file("array_for_sort.txt");
	std::string line;
	int num = 0;

	if (!file.is_open()) {
		std::cout << "Ошибка открытия файла!";
	}
	else {
		while (std::getline(file, line, '\t')) {
			if (ValidFileInput(line)) {
				int support = std::stoi(line);
				array.push_back(support);
				std::cout << "Элемент массива [" << num + 1 << "] равен: " << support << "\n";
				num++;
			}
			else {
				std::cout << "Строка \"" << line << "\"не является целым числом" << "\n" << "\n";
				return false;
			}
		}
	}

	file.close();

}