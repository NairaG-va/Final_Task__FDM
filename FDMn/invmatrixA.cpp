#include <iostream> 
#include <cmath>
#include <vector>

std::vector<std::vector<double>> inv_matrix_A(int n, std::vector<std::vector<double>> matrix) //нахождение обратной матрицы
{
	std::vector<std::vector<double>> inv_matrix;
	
	for (int i = 0; i != n; i++)//делаем обратную матрицу изначально единичной
		{
			std::vector<double> v;
			for (int j = 0; j != n; j++)
				{
					v.push_back((i == j) ? 1.0 : 0.0); //т.е равно 1, если i == j, иначе равно 0
				}
			inv_matrix.push_back(v);

		}
		
		
	for (int k = 0; k != n; k++)//приводим матрицу к верхнетреугольной
		{
			for (int i = k + 1; i != n; i++)
				{
					double temp = matrix[i][k] / matrix[k][k];
					for (int j = 0; j != n; j++)
						{
							matrix[i][j] -= temp * matrix[k][j];
							inv_matrix[i][j] -= temp * inv_matrix[k][j];
						}
				}
		}
	
		
	for (int k = n - 1; k > 0; k--)//далее зануляем все, что выше главной диагонали
		{
			for (int i = k - 1; i >= 0; i--)
				{
					double temp = matrix[i][k] / matrix[k][k];
					for (int j = 0; j != n; j++)
						{
							matrix[i][j] -= temp * matrix[k][j];
							inv_matrix[i][j] -= temp * inv_matrix[k][j];
						}
				}
		}
		
		
	for (int i = 0; i != n; i++)//делим на элементы главной диагонали
		{
			for (int j = 0; j != n; j++)
				{
					inv_matrix[i][j] /= matrix[i][i];
				}
		}

	std::cout << "Inverse matrix A^-1:" << "\n";
	for(int i = 0; i != n; i++)
		{
			for(int j = 0; j != n; j++)
				{
					std::cout << inv_matrix[i][j] << "\t\t";
				}
			std::cout << "\n";	
		}
		
	std::cout << "\n";	
		
	return inv_matrix;
}
