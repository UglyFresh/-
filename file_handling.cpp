#include "file_handling.h"

//���������� ���������������� ������� � ����
void FileInput(std::vector<int> array) {

	std::ofstream file("array_after_sort.txt");

	if (!file.is_open()) {
		std::cout << "������ �������� �����!\n";
	}
	else {
		for (size_t i = 0; i != array.size(); ++i) {
			file << array[i] << "\t";
		}
	}

	file.close();
}

//���������� ������� �� �����
void FileOutput(std::vector<int>& array) {

	std::ifstream file("array_for_sort.txt");
	std::string line;
	int num = 0;

	if (!file.is_open()) {
		std::cout << "������ �������� �����!";
	}
	else {
		while (std::getline(file, line, '\t')) {
			int support{ std::stoi(line) };
			std::cout << "������� ������� [" << num + 1 << "] �����: " << support << "\n";
			array.push_back(support);
			num++;
		}
	}

	file.close();

}