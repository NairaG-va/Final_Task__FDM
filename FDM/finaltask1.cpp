//Финальное задание - метод конечных разностей
#include <iostream> 
#include <cmath>
#include <vector> 
#include <gtest/gtest.h>

#include "matrixA.cpp"
#include "invmatrixA.cpp"
#include "vector.cpp"
#include "vecy.cpp"
#include "vector1.cpp"
#include "vec1y.cpp"
#include "dist.cpp"

std::vector<double> res;


TEST(matrixTests,values)
{
	std::vector<double> testVec = 
	{
		{2.0}, {2.03669}, {2.07105}, {2.10111}, {2.12478}, {2.13979}, {2.14374}, {2.13416}, {2.10856}, {2.06457}, {2.0} 
	};
	
	for(int i = 0; i < 11; i++)
	{
		ASSERT_LT(abs(res[i] - testVec[i]), 2e-2);
	}
}

int main()
{
	int n = 11;
	double h = 0.1;
	
	std::vector<std::vector<double>> matrix = matrix_A(n, h) ;
	std::vector<std::vector<double>> inv_matrix = inv_matrix_A(n, matrix);
	std::vector<double> vec = vector_(n, h);
	std::vector<double> y = vec_y(n, inv_matrix, vec);


	std::vector<double> vec1 = vector1_(n, h, y);
	std::vector<double> y1 = vec1_y(n, inv_matrix, vec1);
	
	double d = 0.0;
	d = dist (n, h, y, y1);
	std::cout << "d = " << d << "\n\n";	
	
	while (dist (n, h, y, y1) >= 1.e-6)
	{
		y = y1;
		//for(int i = 0; i != n; i++)
		//{
		//	std::cout << "y[" << i << "]= " << y[i] << "\n";	
		//}
		//std::cout << "\n";
		
		//for(int i = 0; i != n; i++)
		//{
		//	std::cout << "y1[" << i << "]= " << y1[i] << "\n";	
		//}
		//std::cout << "\n";

		vec1 = vector1_(n, h, y);
		y1 = vec1_y(n, inv_matrix, vec1);	
	}
	res = y1;
	d = dist (n, h, y, y1);
	std::cout << "d = " << d << "\n\n";
	
	::testing::InitGoogleTest();
	
	return RUN_ALL_TESTS();
}
