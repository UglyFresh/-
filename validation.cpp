#include "validation.h"

//�������� ����������������� �����
int ValidInput() {
	
    int number;
    while (!(std::cin >> number)) {
        std::cout << "������ �����! ������� ������������ �����: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
 
    return number;

}