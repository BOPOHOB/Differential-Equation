#pragma once

#include "differentialequationsolver.h"

template <typename T>
class Euler : public DifferentialEquationSolver<T> {
	Expression equation;
public:
	Euler(Expression equation, double dt, const InitialCondition<T>& t0)
		: DifferentialEquationSolver(dt, t0), equation(equation) { }

	ValueType operator()(const double& tEnd) const final
	{
		ValueType result(start.initialValue);
		double t(start.zero≈ime);

		while (t < tEnd) {
			t += step;
			result = equation(result, step);
		}
		return std::move(result);
	}

	ValueType error(const double& tEnd, std::function<ValueType(double)> solution, std::function<ValueType(ValueType)> absOperator, const Norm& norm) const final
	{
		ValueType val(start.initialValue);
		double t(start.zero≈ime);
		std::vector<ValueType> deficiency;
		deficiency.reserve(static_cast<int>((tEnd - t) / step + 1.));

		while (t < tEnd) {
			t += step;
			val = equation(val, step);

			deficiency.emplace_back(absOperator(val - solution(t)));
		}
		return norm(deficiency);
	}
};
