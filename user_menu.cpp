#include "file_handling.h"

#define GREETING													\
	"Доброго времени суток \n"										\
	"Работу выполнил Кузьмин Владислав Евгеньевич, группа 434\n"	\
	"Вариант 11\n"													\

#define MENU														\
	"1.Ввести данные через консоль\n"								\
	"2.Загрузить данные из файла\n"									\
	"3.Завершить работу программы\n"								\

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
		std::cout << "Выберите желаемый пункт меню: " << "\n" << MENU;
		choice = ValidUserInput();

		while (begin_choice < choice && choice > finish_choice) {
			std::cout << "Ошибка! Выберите одно из предложенных значений: ";
			choice = ValidUserInput();
			std::cout << "\n";
		}
		choice = static_cast<user_choice>(choice);

		switch (choice) {
		case MANUAL_INPUT:
		
			int value;
			int array_size;

			std::cout << "Введите желаемый размер массива: ";
			array_size = ValidUserInput();
			if (array_size < 0) {
				std::cout << "Введите значение больше нуля: ";
				array_size = ValidUserInput();
			}
			array.resize(array_size);
			for (size_t i = 0; i != array_size; ++i) {
				std::cout << "Введите значение: ";
				value = ValidUserInput();
				array[i] = value;
				std::cout << "\n";
			}

			std::cout << "Массива до сортировки: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "Элемент [" << i + 1 << "] равен: " << array[i] << "\n";
			}

			sort.Alghoritm(array, 0, array.size() - 1);
			std::cout << "Массива после сортировки: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "Элемент [" << i + 1 << "] равен: " << array[i] << "\n";
			}

			std::cout << "Желаете сохранить массив в файл? \n 1 - Сохранить, 2 - Не сохранять\n";
			save_choice = ValidUserInput();
			while (save_choice != 1 && save_choice != 2){
				std::cout << "Ошибка! Выберите из предложенных значений: ";
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
			std::cout << "Массива после сортировки: " << "\n";
			for (size_t i = 0; i != array.size(); ++i) {
				std::cout << "Элемент [" << i + 1 << "] равен: " << array[i] << "\n";
			}

			std::cout << "Желаете сохранить массив в файл? \n 1 - Сохранить, 2 - Не сохранять\n";
			save_choice = ValidUserInput();
			while (save_choice != 1 && save_choice != 2) {
				std::cout << "Ошибка! Выберите из предложенных значений: ";
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