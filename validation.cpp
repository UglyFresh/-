#include "validation.h"

int ValidUserInput() {
	
    int choice;
    while (!(std::cin >> choice)) {
        std::cout << "Ошибка ввода! Введите вещественное число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
 
    return choice;

}

bool ValidFileInput(const std::string str) {

    try {
        size_t pos;
        std::stoi(str, &pos);
        return pos == str.size();
    }
    catch (std::invalid_argument& e) { return false; }
    catch (std::out_of_range& e) { return false; }

}