#include "file_handling.h"

#define GREETING													\
	"������� ������� ����� \n"										\
	"������ �������� ������� ��������� ����������, ������ 434\n"	\
	"������� 11\n"													\

#define MENU														\
	"1.������ ������ ����� �������\n"								\
	"2.��������� ������ �� �����\n"									\
	"3.��������� ������ ���������\n"								\

enum user_choice { MANUAL_INPUT = 1, FILE_INPUT, END };

int main() {

	setlocale(LC_ALL, "RU");

	std::cout << GREETING;

	const int begin_choice = 1, finish_choice = 3;
	int choice;
	int save_choice;
	std::vector <int> array;
	QuickSort sort;

	while (true){
		std::cout << "�������� �������� ����� ����: " << "\n" << MENU;
		choice = ValidUserInput();

		while (begin_choice < choice && choice > finish_choice) {
			std::cout << "������! �������� ���� �� ������������ ��������: ";
			choice = ValidUserInput();
			std::cout << "\n";
		}
		choice = static_cast<user_choice>(choice);

		switch (choice) {
		case MANUAL_INPUT:
		
			int value;
			int array_size;

			std::cout << "������� �������� ������ �������: ";
			array_size = ValidUserInput();
			if (array_size < 0) {
				std::cout << "������� �������� ������ ����: ";
				array_size = ValidUserInput();
			}
			array.resize(array_size);
			for (size_t i = 0; i != array_size; ++i) {
				std::cout << "������� ��������: ";
				value = ValidUserInput();
				array[i] = value;
				std::cout << "\n";
			}

			std::cout << "������� �� ����������: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "������� [" << i + 1 << "] �����: " << array[i] << "\n";
			}

			sort.Alghoritm(array, 0, array.size() - 1);
			std::cout << "������� ����� ����������: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "������� [" << i + 1 << "] �����: " << array[i] << "\n";
			}

			std::cout << "������� ��������� ������ � ����? \n 1 - ���������, 2 - �� ���������\n";
			save_choice = ValidUserInput();
			while (save_choice != 1 && save_choice != 2){
				std::cout << "������! �������� �� ������������ ��������: ";
				save_choice = ValidUserInput();
				std::cout << "\n";
			}

			if (save_choice == 1) {
				FileInput(array);
			}

			array.clear();

			break;
		
		case FILE_INPUT:
		
			if (!FileOutput(array)) { break; }

			sort.Alghoritm(array, 0, array.size() - 1);
			std::cout << "������� ����� ����������: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "������� [" << i + 1 << "] �����: " << array[i] << "\n";
			}

			std::cout << "������� ��������� ������ � ����? \n 1 - ���������, 2 - �� ���������\n";
			save_choice = ValidUserInput();
			while (save_choice != 1 && save_choice != 2) {
				std::cout << "������! �������� �� ������������ ��������: ";
				save_choice = ValidUserInput();
				std::cout << "\n";
			}

			if (save_choice == 1) {
				FileInput(array);
			}

			array.clear();

			break;
		
		case END: return EXIT_SUCCESS;
		}

	}

}