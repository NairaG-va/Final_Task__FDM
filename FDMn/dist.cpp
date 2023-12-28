#include <iostream> 
#include <cmath>
#include <vector>

double dist (int n, double h, std::vector<double>& y, std::vector<double>& y1)
{
	double sum = 0.0;
	for (int i = 0; i != n; i++)
		{ 
			sum += h*(y1[i]-y[i])*(y1[i]-y[i]);
		}
	return sum;
} 
