#include <iostream>
#include <functional>
#include <cmath>

#include "euler.h"
#include "rungekutta.h"
#include "norm.h"

template <typename T>
double solvertTester(DifferentialEquationSolver<T>& solver, std::function<T(double)> solve, Norm& norma, const double& tEnd) {
	return solver.error(tEnd, solve, [](const double& v)->double { return fabs(v); }, norma);
}

int main() 
{
	static const double gama(1.0);
	static const double t1(0.0);
	static const InitialCondition<double> t0(20.0);
	static const double dt(1e-3);
	static const double tEnd(10.0);

	auto eulerEquationSolve([](double t, double dt)->double { return (t + dt * gama * t1) / (1 + dt * gama); });
	auto rightSide([](double t, double y)->double { return -gama * (y - t1); });
	std::function<double(double)> equationSolve([](double t) { return t1 + (t0.initialValue - t1) * exp(-gama * t); });

	std::cout << "Euler: " << solvertTester(Euler<double>(eulerEquationSolve, dt, t0), equationSolve, MNorm(), tEnd) << std::endl;
	std::cout << "RungeKutta: " << solvertTester(RungeKutta<double>(rightSide, dt, t0), equationSolve, MNorm(), tEnd) << std::endl;

	return !true && !false;
}
