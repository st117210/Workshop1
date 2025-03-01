#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Функция для вычисления среднего значения
double avarage(const vector<double>& data)
{
	double sum = 0.0;
	for (double u : data)
	{
		sum += u;
	}
	return sum / data.size();
}

vector<double> standartDeviation(vector<double>& randDevAr)
{
	vector<double> standAr;
	for (int i = 0; i < randDevAr.size(); i++)
	{
		double t = randDevAr[i];
		standAr.push_back(t * t);
	}
	return standAr;
}

vector<double> randomDeviation(const vector<double>& data, double avarage)
{
	vector<double> randDevAr;
	for (int i = 0; i < data.size(); i++)
	{
		randDevAr.push_back(data[i] - avarage);
	}

	return randDevAr;
}

int main()
{
	setlocale(LC_ALL, "Ru");

	ifstream file("Точные.csv");
	string line;
	vector<double> values;

	if (!file.is_open())
	{
		cerr << "Ошибка открытия файла!" << endl;
		return 1;
	}

	// Чтение данных из CSV
	while (getline(file, line))
	{
		if (line.empty())
		{
			continue;  // Пропускаем пустые строки
		}

		values.push_back(stod(line));
	}

	// Закрываем файл после чтения
	file.close();

	// Вычисление среднего значения
	double mean = avarage(values);
	cout << "Среднее значение: " << mean << endl;

	// Вычисление отклонений от среднего для каждого значения
	cout << "Отклонения от среднего: " << endl;

	vector<double> ar1 = randomDeviation(values, mean);

	for (int i = 0; i < ar1.size(); i++)
	{
		cout << ar1[i] << "\n";
	}
	cout << endl;

	double sum1 = 0;
	for (int i = 0; i < ar1.size(); i++)
	{
		sum1 += abs(ar1[i]);
	}
	cout << "Сумма случайных отклонений от среднего: " << sum1 << endl;
	// Вычисление стандартного отклонения

	cout << "Стандартное отклонение: " << endl;

	vector<double> ar2 = standartDeviation(ar1);
	for (int i = 0; i < ar2.size(); i++)
	{
		cout << i + 1 << ". " << ar2[i] << "\n";
	}
	cout << endl;

	double sum2 = 0;
	for (int i = 0; i < ar1.size(); i++)
	{
		sum2 += abs(ar2[i]);
	}

	cout << "Сумма стандартных отклонений от среднего: " << sum2 << endl;

	double sigma = sqrt(sum2 / double(values.size() - 1));
	cout << "Среднеквадратичное отклонение: " << sigma << endl;

	double deltaU = sigma / sqrt(values.size());
	cout << "Средняя квадратичная погрешность среднего: " << deltaU << endl;

	cout << "Погрешность: " << mean << " +- " << deltaU << endl;


	return 0;
}
