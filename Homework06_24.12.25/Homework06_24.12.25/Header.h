#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cmath>

class Dataset {
private:
    std::vector<std::vector<std::string>> data; // Таблица данных
    std::vector<std::string> headers;           // Заголовки столбцов
    bool hasIndex;                              // Есть ли индексный столбец

    void LoadData(const std::string& filePath, const std::vector<std::string>& customHeaders);

public:
    explicit Dataset(const std::string& filePath, bool generateIndex = false, const std::vector<std::string>& customHeaders = {});

    void Head(int n = 5) const;
    void Tail(int n = 5) const;
    void Insert(int index, const std::vector<std::string>& row);
    void Remove(int index);
    void Describe(const std::string& columnName) const;

    std::vector<std::string>& operator[](int index);
    const std::vector<std::string>& operator[](int index) const;
};

#endif
