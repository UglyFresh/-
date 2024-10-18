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

bool FileOutput(std::vector<int>& array) {

	std::ifstream file("array_for_sort.txt");
	std::string line;
	int num = 0;

	if (!file.is_open()) {
		std::cout << "������ �������� �����!";
	}
	else {
		while (std::getline(file, line, '\t')) {
			if (ValidFileInput(line)) {
				int support = std::stoi(line);
				array.push_back(support);
				std::cout << "������� ������� [" << num + 1 << "] �����: " << support << "\n";
				num++;
			}
			else {
				std::cout << "������ \"" << line << "\"�� �������� ����� ������" << "\n" << "\n";
				return false;
			}
		}
	}

	file.close();

}