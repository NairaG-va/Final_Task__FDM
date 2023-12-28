#include <iostream> 
#include <cmath>
#include <vector>

//начинаем след шаг итерации
std::vector<double> vector1_(int n, double h, std::vector<double>& y)
{
	std::vector<double> vec1(n);
	vec1[0] = 2;	
	for (int i = 1; i != n-1; i++)
	{
		vec1[i] = -(i*h) - (i*h)*(i*h)*y[i];
	}
	vec1[n-1] = 2;
		
	for(int i = 0; i != n; i++)
		{
			std::cout << "vec1[" << i << "]= " << vec1[i] << "\n";	
		}
	std::cout << "\n";

	return vec1;
}
