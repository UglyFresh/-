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

	for (;;){
		std::cout << "�������� �������� ����� ����: " << "\n" << MENU;
		choice = ValidInput();

		while (begin_choice < choice && choice > finish_choice) {
			std::cout << "������! �������� ���� �� ������������ ��������: ";
			choice = ValidInput();
			std::cout << "\n";
		}
		choice = static_cast<user_choice>(choice);

		switch (choice) {
		case MANUAL_INPUT:
		
			int value;
			size_t array_size;

			std::cout << "������� �������� ������ �������: ";
			array_size = ValidInput();
			array.resize(array_size);
			for (size_t i = 0; i != array_size; ++i) {
				std::cout << "������� ��������: ";
				value = ValidInput();
				array[i] = value;
				std::cout << "\n";
			}

			std::cout << "������� �� ����������: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "������� [" << i + 1 << "] �����: " << array[i] << "\n";
			}

			QuickSort::Sort(array, 0, array.size() - 1);
			std::cout << "������� ����� ����������: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "������� [" << i + 1 << "] �����: " << array[i] << "\n";
			}

			std::cout << "������� ��������� ������ � ����? \n 1 - ���������, 2 - �� ���������\n";
			save_choice = ValidInput();
			while (save_choice != 1 && save_choice != 2){
				std::cout << "������! �������� �� ������������ ��������: ";
				save_choice = ValidInput();
				std::cout << "\n";
			}

			if (save_choice == 1) {
				FileInput(array);
			}

			array.clear();

			break;
		
		case FILE_INPUT:
		
			FileOutput(array);

			QuickSort::Sort(array, 0, array.size() - 1);
			std::cout << "������� ����� ����������: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "������� [" << i + 1 << "] �����: " << array[i] << "\n";
			}

			std::cout << "������� ��������� ������ � ����? \n 1 - ���������, 2 - �� ���������\n";
			save_choice = ValidInput();
			while (save_choice != 1 && save_choice != 2) {
				std::cout << "������! �������� �� ������������ ��������: ";
				save_choice = ValidInput();
				std::cout << "\n";
			}

			if (save_choice == 1) {
				FileInput(array);
			}

			break;
		
		case END: return EXIT_SUCCESS;
		}

	}


}