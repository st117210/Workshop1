#include "function.h"

// Функция для вычисления среднего значения

int main()
{
	setlocale(LC_ALL, "Ru");

	std::vector<double> values;

	if (readDataFromFile("Accurate.txt", values) == 1)
	{
		return 1;
	}



	// Вычисление среднего значения
	double avar = avarage(values);
	std::cout << "Среднее значение: " << avar << std::endl;

	// Вычисление отклонений от среднего для каждого значения
	std::cout << "Отклонения от среднего: " << std::endl;

	std::vector<double> devFromTheAver = randomDeviation(values, avar);
	for (int i = 0; i < devFromTheAver.size(); i++)
	{
		std::cout << devFromTheAver[i] << "\n";
	}
	std::cout << std::endl;

	double sumDevFromTheAver = 0;
	for (int i = 0; i < devFromTheAver.size(); i++)
	{
		sumDevFromTheAver += abs(devFromTheAver[i]);
	}
	std::cout << "Сумма случайных отклонений от среднего: " << sumDevFromTheAver << std::endl;
	// Вычисление стандартного отклонения

	std::cout << "Стандартное отклонение: " << std::endl;

	std::vector<double> arrayStDev = standartDeviation(devFromTheAver);
	for (int i = 0; i < arrayStDev.size(); i++)
	{
		std::cout << i + 1 << ". " << arrayStDev[i] << "\n";
	}
	std::cout << std::endl;

	double sumStDev = 0;
	for (int i = 0; i < devFromTheAver.size(); i++)
	{
		sumStDev += abs(arrayStDev[i]);
	}

	std::cout << "Сумма стандартных отклонений от среднего: " << sumStDev << std::endl;

	double sigma = sqrt(sumStDev / double(values.size() - 1));
	std::cout << "Среднеквадратичное отклонение: " << sigma << std::endl;

	double deltaU = sigma / sqrt(values.size());
	std::cout << "Средняя квадратичная погрешность среднего: " << deltaU << std::endl;

	std::cout << "Погрешность: " << avar << " +- " << deltaU << std::endl;


	std::ofstream file;
	file.open("Result.txt");
	if (file.is_open())
	{

		for (int i = 0; i < devFromTheAver.size(); i++)
		{
			file << i + 1 << " & ";
			file << std::fixed << std::setprecision(4) <<  devFromTheAver[i] << " & ";
			file << std::fixed << std::setprecision(12) << arrayStDev[i] << " \\" << "\\" << std::endl;
		}

		file << "Это строка текста для записи в файл." << std::endl;
		file << 123 << std::endl;
		file << 3.14159 << std::endl;


		file.close(); // Закрываем файл
	}

	return 0;
}
