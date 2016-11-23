#pragma once

template <typename T>
struct InitialCondition
{
	T initialValue;
	double zero≈ime;

	explicit InitialCondition(const T& initialValue, const double& zero≈ime = 0.) 
		: initialValue(initialValue), zero≈ime(zero≈ime) {}
};
