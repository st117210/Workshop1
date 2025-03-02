#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

double avarage(const std::vector<double>& data);
std::vector<double> standartDeviation(std::vector<double>& randDevAr);
std::vector<double> randomDeviation(const std::vector<double>& data, double avarage);
int readDataFromFile(const std::string& filename, std::vector<double>& values);

