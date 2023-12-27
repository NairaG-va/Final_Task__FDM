#include <iostream> 
#include <cmath>
#include <vector>

std::vector<double> vec1_y(int n, std::vector<std::vector<double>>& inv_matrix, std::vector<double>& vec1)
{
	std::vector<double> y1;
	
	for (auto& v: inv_matrix)
	{
		double temp = 0.0;
		for(int j = 0; j != n; j++) 
		{
			temp += v[j] * vec1[j];
		}
		y1.push_back(temp);
	}
	
	for(int i = 0; i != n; i++)
		{
			std::cout << "y1[" << i << "]= " << y1[i] << "\n";	
		}
		std::cout << "\n";
	return y1;
}
