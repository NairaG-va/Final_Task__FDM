#include <iostream> 
#include <cmath>
#include <vector>

std::vector<std::vector<double>> matrix_A(int n, double h) 
{
	std::vector<std::vector<double>> matrix;
	
	for (int i = 0; i != n; i++)
	{
		std::vector<double> v;
		for (int j = 0; j != n; j++)
		{
			v.push_back(0.0);
		}
		matrix.push_back(v);
	}
	
	for (int i = 0; i != n; i++)
	{
		for (int j = 0; j != n; j++)
		{
			if (i == j){
				matrix[i][j] = -(2.0 + h*sqrt(i*h))/(h*h);
			} else if (i == j - 1){
				 matrix[i][j] = 1.0/(h*h);
			} else if (i == j + 1){
				matrix[i][j] = (1.0 + h*sqrt(i*h))/(h*h);
			} else {
				matrix[i][j] = 0.0;
			}
		}
	}
	
	matrix[0][0] = 1.0;
	matrix[0][1] = 0.0;
	matrix[10][9] = 0.0;
	matrix[10][10] = 1.0;
	
	std::cout << "Matrix A:" << "\n";
	for(int i = 0; i != n; i++)
		{
			for(int j = 0; j != n; j++)
				{
					std::cout << matrix[i][j] << "\t\t";
				}
			std::cout << "\n";	
		}
	
	return matrix;
}
