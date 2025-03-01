#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// ������� ��� ���������� �������� ��������
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

	ifstream file("������.csv");
	string line;
	vector<double> values;

	if (!file.is_open())
	{
		cerr << "������ �������� �����!" << endl;
		return 1;
	}

	// ������ ������ �� CSV
	while (getline(file, line))
	{
		if (line.empty())
		{
			continue;  // ���������� ������ ������
		}

		values.push_back(stod(line));
	}

	// ��������� ���� ����� ������
	file.close();

	// ���������� �������� ��������
	double mean = avarage(values);
	cout << "������� ��������: " << mean << endl;

	// ���������� ���������� �� �������� ��� ������� ��������
	cout << "���������� �� ��������: " << endl;

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
	cout << "����� ��������� ���������� �� ��������: " << sum1 << endl;
	// ���������� ������������ ����������

	cout << "����������� ����������: " << endl;

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

	cout << "����� ����������� ���������� �� ��������: " << sum2 << endl;

	double sigma = sqrt(sum2 / double(values.size() - 1));
	cout << "������������������ ����������: " << sigma << endl;

	double deltaU = sigma / sqrt(values.size());
	cout << "������� ������������ ����������� ��������: " << deltaU << endl;

	cout << "�����������: " << mean << " +- " << deltaU << endl;


	return 0;
}
