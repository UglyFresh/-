#include "validation.h"

//Проверка пользовательского ввода
int ValidInput() {
	
    int number;
    while (!(std::cin >> number)) {
        std::cout << "Ошибка ввода! Введите вещественное число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
 
    return number;

}