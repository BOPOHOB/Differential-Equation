#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

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

class ManhattanNorm : public Norm
{
public:
	double operator() (const std::vector<double>& v) const final
	{
		return std::accumulate(v.begin(), v.end(), 0.);
	}
};