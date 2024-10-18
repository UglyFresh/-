#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/// <summary>
/// Проверка пользовательского ввода
/// </summary>
/// <returns></returns>
int ValidUserInput();
/// <summary>
/// Проверка ввода из файла
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
bool ValidFileInput(const std::string str);
