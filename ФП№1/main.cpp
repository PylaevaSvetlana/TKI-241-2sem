#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

int main()
{
	std::setlocale(LC_ALL, "RU");

	std::vector<double> vector;
	std::cout << "Введите числа" << std::endl;
	std::istream_iterator<double> begin(std::cin);
	std::istream_iterator<double> end;
	copy(begin, end, back_inserter(vector));

	if (vector.size() < 2)
	{
		std::cout << "Введено меньше двух чисел" << std::endl;
		return 1;
	}

	std::vector<double> ChetVector;
	int index = 0;
	std::remove_copy_if(vector.begin(), vector.end(), back_inserter(ChetVector), [&index](double) { return (index++ % 2) == 0; });

	std::cout << "Чётные" << std::endl;
	std::ostream_iterator<double> out(std::cout, " ");
	copy(ChetVector.begin(), ChetVector.end(), out);

	return 0;
}