#pragma once
#include "quick_sort.h"

/// <summary>
/// Сохранение отсортиоованного массива в файл
/// </summary>
/// <param name="array"> МА </param>
void FileInput(std::vector<int> array);

/// <summary>
/// Получение данных из файла
/// </summary>
/// <param name="array"></param>
bool FileOutput(std::vector<int>& array);

