#pragma once

#include <vector>
#include <algorithm>

class Norm
{
public:
	Norm() {}

	virtual double operator()(const std::vector<double>&) const = 0;
};

class MNorm : public Norm
{
public:
	double operator() (const std::vector<double>& v) const final
	{
		return *std::max_element(v.begin(), v.end());
	}
};
