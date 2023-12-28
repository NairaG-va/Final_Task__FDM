#include <iostream> 
#include <cmath>
#include <vector> 

std::vector<double> vec_y(int n, std::vector<std::vector<double>>& inv_matrix, std::vector<double>& vec)
{
	std::vector<double> y;
	
	for (auto& v: inv_matrix)
	{
		double temp = 0.0;
		for(int j = 0; j != n; j++) 
		{
			temp += v[j] * vec[j];
		}
		y.push_back(temp);
	}
	
	for(int i = 0; i != n; i++)
		{
			std::cout << "y[" << i << "]= " << y[i] << "\n";	
		}
		std::cout << "\n";
		std::cout << "/////////////////////////////////////////////////////////////////////////////////////////////////////////////" << "\n"; //для отделения от следующего шага итерации
		
	return y;
}
