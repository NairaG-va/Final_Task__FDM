#include <iostream> 
#include <cmath>
#include <vector> 

std::vector<double> vector_(int n, double h)
{
	std::vector<double> vec(n);
	vec[0] = 2;	
	for (int i = 1; i != n-1; i++)
	{
		vec[i] = -(i*h) - (i*h)*(i*h)*(i*h);	
	}
	vec[n-1] = 2;
		
	for(int i = 0; i != n; i++)
		{
			std::cout << "vec[" << i << "]= " << vec[i] << "\n";	
		}
	std::cout << "\n";

	return vec;
}
