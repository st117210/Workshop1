#include "function.h"

double avarage(const std::vector<double>& data)
{
	double sum = 0.0;
	for (int i = 0; i < data.size(); ++i)
	{
		sum += data[i];
	}
	return sum / data.size();
}

std::vector<double> randomDeviation(const std::vector<double>& data, double avarage)
{
	std::vector<double> randDevAr;
	for (int i = 0; i < data.size(); i++)
	{
		randDevAr.push_back(data[i] - avarage);
	}

	return randDevAr;
}

std::vector<double> standartDeviation(std::vector<double>& randDevAr)
{
	std::vector<double> standAr;
	for (int i = 0; i < randDevAr.size(); i++)
	{
		double t = randDevAr[i];
		standAr.push_back(t * t);
	}
	return standAr;
}

int readDataFromFile(const std::string& filename, std::vector<double>& values)
{
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "������ �������� �����!" << std::endl;
		return 1;
	}

	std::string line;
	while (getline(file, line))
	{
		if (line.empty())
		{
			continue;
		}

		values.push_back(std::stod(line));
	}

	file.close();

	return 0;
}

