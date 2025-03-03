#include "function.h"

int main()
{
	std::vector<double> values;

	if (readDataFromFile("Accurate.txt", values) == 1)
	{
		return 1;
	}

	int n = values.size();
	double avar = avarage(values);
	std::vector<double> devFromTheAver = randomDeviation(values, avar);
	std::vector<double> arrayStDev = standartDeviation(devFromTheAver);
	double sumStanDev = sumStDev(arrayStDev);
	double sigm = sigma(sumStanDev, double(n));
	double deltU = deltaU(sigm, double(n));

	std::ofstream file;
	file.open("Result.tex");
	if (file.is_open())
	{
		file << "\\begin{tabular}{|c|c|c|}" << std::endl;
		file << "\\hline" << std::endl;
		file << "\\textnumero & $d_i = U_i - \overline{U}$ & $d_i^2 = (U_i - \overline{U})^2$" << " \\" << "\\" << std::endl;
		file << "\\hline" << std::endl;
		for (int i = 0; i < n; i++)
		{
			file << i + 1 << " & ";
			file << std::fixed << std::setprecision(4) << devFromTheAver[i] << " & ";
			file << std::fixed << std::setprecision(12) << arrayStDev[i] << " \\" << "\\" << std::endl;
		}
		file << "\\hline" << std::endl;
		file << "\\end{tabular}" << std::endl;
		file << std::endl;

		file << "\\begin{tabular}{|c|c|}" << std::endl;
		file << "\\hline" << std::endl;
		file << "Values  & Calculation results" << " \\" << "\\" << std::endl;
		file << "\\hline" << std::endl;
		file << "\\overline{U} & " << std::fixed << std::setprecision(6) << avar << " \\" << "\\" << std::endl;
		file << "$\\sum_{i=1}^{50} |d_i|$ & " << sumDevAv(devFromTheAver) << " \\" << "\\" << std::endl;
		file << "$\\sum_{i=1}^{50} d_i^2$ & " << sumStanDev << " \\" << "\\" << std::endl;
		file << "\\sigma & " << sigm << " \\" << "\\" << std::endl;
		file << "\\Delta U & " << deltU << " \\" << "\\" << std::endl;
		file << "U & " << avar << " $\\pm$ " << deltU << " \\" << "\\" << std::endl;
		file << "\\hline" << std::endl;
		file << "\\end{tabular}" << std::endl;

		file.close();
	}

	return 0;
}
