#pragma once

#include <functional>
#include <algorithm>
#include <vector>
#include "norm.h"
#include "initialcondition.h"

template <typename T>
class DifferentialEquationSolver {
public:
	typedef T ValueType;
	typedef std::function<ValueType(double, double)> Expression;
protected:
	double step;
	InitialCondition<T> start;

public:
	DifferentialEquationSolver(const double& dt, const InitialCondition<T>& start)
		: step(dt), start(start) { }

	virtual ValueType operator()(const double& tEnd) const = 0;

	ValueType solve(const double& t) const { return std::move((*this)(t)); }

	virtual ValueType error(const double& tEnd, std::function<ValueType(double)> solution, std::function<ValueType(ValueType)> absOperator, const Norm&) const = 0;
};
