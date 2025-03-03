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
double sumDevAv(const std::vector<double>& devFromTheAver);
double sumStDev(const std::vector<double>& arrayStDev);
double sigma(double sumStanDev, double n);
double deltaU(double sigma, double n);
int readDataFromFile(const std::string& filename, std::vector<double>& values);

