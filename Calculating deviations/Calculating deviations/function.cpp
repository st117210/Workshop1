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

double sumDevAv(const std::vector<double>& devFromTheAver)
{
	double sum = 0;
	for (int i = 0; i < devFromTheAver.size(); i++)
	{
		sum += abs(devFromTheAver[i]);
	}
	return sum;
}

double sumStDev(const std::vector<double>& arrayStDev)
{ 
	double sum = 0;
	for (int i = 0; i < arrayStDev.size(); i++)
	{
		sum += arrayStDev[i];
	}
	return sum;
}

double sigma(double sumStanDev, double n)
{
	return sqrt(sumStanDev / double(n - 1));
}

double deltaU(double sigma, double n)
{
	return (sigma / sqrt(n));
}

int readDataFromFile(const std::string& filename, std::vector<double>& values)
{
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Ошибка открытия файла!" << std::endl;
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

