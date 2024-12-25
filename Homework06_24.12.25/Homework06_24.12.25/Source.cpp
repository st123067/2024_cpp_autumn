#include "Header.h"
#include <numeric> 

Dataset::Dataset(const std::string& filePath, bool generateIndex, const std::vector<std::string>& customHeaders)
    : hasIndex(generateIndex) {
    LoadData(filePath, customHeaders);
}

void Dataset::LoadData(const std::string& filePath, const std::vector<std::string>& customHeaders) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::string line;
    if (std::getline(file, line)) {
        std::istringstream headerStream(line);
        std::string header;

        while (std::getline(headerStream, header, ',')) {
            headers.push_back(header);
        }

        if (!customHeaders.empty()) {
            headers = customHeaders;
        }
        else if (headers.empty()) {
            throw std::runtime_error("No headers provided and file headers are empty.");
        }
    }

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream rowStream(line);
        std::string value;

        while (std::getline(rowStream, value, ',')) {
            row.push_back(value);
        }

        data.push_back(row);
    }
}

void Dataset::Head(int n) const {
    n = std::min(n, static_cast<int>(data.size()));
    for (const auto& header : headers) {
        std::cout << header << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; ++i) {
        for (const auto& value : data[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

void Dataset::Tail(int n) const {
    n = std::min(n, static_cast<int>(data.size()));
    for (const auto& header : headers) {
        std::cout << header << " ";
    }
    std::cout << std::endl;

    for (int i = data.size() - n; i < data.size(); ++i) {
        for (const auto& value : data[i]) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

void Dataset::Insert(int index, const std::vector<std::string>& row) {
    if (index < 0 || index > data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    data.insert(data.begin() + index, row);
}

void Dataset::Remove(int index) {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    data.erase(data.begin() + index);
}

void Dataset::Describe(const std::string& columnName) const {
    auto it = std::find(headers.begin(), headers.end(), columnName);
    if (it == headers.end()) {
        throw std::invalid_argument("Column not found: " + columnName);
    }

    int colIndex = std::distance(headers.begin(), it);
    std::vector<double> columnValues;

    for (const auto& row : data) {
        columnValues.push_back(std::stod(row[colIndex]));
    }

    double max = *std::max_element(columnValues.begin(), columnValues.end());
    double min = *std::min_element(columnValues.begin(), columnValues.end());
    double sum = std::accumulate(columnValues.begin(), columnValues.end(), 0.0);
    double mean = sum / columnValues.size();
    double variance = 0.0;

    for (const auto& value : columnValues) {
        variance += (value - mean) * (value - mean);
    }
    variance /= columnValues.size();
    double stddev = std::sqrt(variance);

    std::cout << "Column: " << columnName << std::endl;
    std::cout << "Max: " << max << " Min: " << min << " Mean: " << mean << " StdDev: " << stddev << std::endl;
}

std::vector<std::string>& Dataset::operator[](int index) {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

const std::vector<std::string>& Dataset::operator[](int index) const {
    if (index < 0 || index >= data.size()) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}
