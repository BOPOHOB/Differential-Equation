#pragma once

#include "differentialequationsolver.h"

template <typename T>
class RungeKutta : public DifferentialEquationSolver<T>
{
	std::function<T(double, double)> rightSide;

public:
	RungeKutta(std::function<T(double, double)> rightSude, double dt, const InitialCondition<T>& t0)
		: DifferentialEquationSolver(dt, t0)
		, rightSide(rightSude) {}

	ValueType operator()(const double& tEnd) const final 
	{
		ValueType result(start.initialValue);
		double t(start.zero≈ime);

		while (t < tEnd) {
			const T k1(rightSide(t           , result));
			const T k2(rightSide(t + step / 2, result + k1 * step / 2));
			const T k3(rightSide(t + step / 2, result + k2 * step / 2));
			const T k4(rightSide(t + step    , result + k3 * step));
			
			t += step;
			result = result + step / 6 * (k1 + k2 + k2 + k3 + k3 + k4);
		}
		return std::move(result);
	}

	ValueType error(const double& tEnd, std::function<ValueType(double)> solution, std::function<ValueType(ValueType)> absOperator, const Norm& norm) const final
	{
		ValueType result(start.initialValue);
		double t(start.zero≈ime);

		std::vector<ValueType> deficiency;
		deficiency.reserve(static_cast<int>((tEnd - t) / step + 1.));

		while (t < tEnd) {
			const T k1(rightSide(t, result));
			const T k2(rightSide(t + step / 2, result + k1 * step / 2));
			const T k3(rightSide(t + step / 2, result + k2 * step / 2));
			const T k4(rightSide(t + step, result + k3 * step));

			t += step;
			result = result + step / 6 * (k1 + k2 + k2 + k3 + k3 + k4);

			deficiency.emplace_back(absOperator(result - solution(t)));
		}
		return norm(deficiency);
	}
};
