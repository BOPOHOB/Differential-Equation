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

	std::cout << "For equation dT(t)/dt=-gama(T(t)-T1) where T1 is constatnt:" << std::endl;
	std::cout << "Euler error: " << solvertTester(Euler<double>(eulerEquationSolve, dt, t0), equationSolve, MNorm(), tEnd) << std::endl;
	std::cout << "RungeKutta error: " << solvertTester(RungeKutta<double>(rightSide, dt, t0), equationSolve, MNorm(), tEnd) << std::endl;

	static const double m(10.0);
	static const double g(9.8);
	static const double alpha(1.0);

	static const InitialCondition<double> v0(0.0);
	
	auto rightSide2([](double t, double v)->double { return (m * g - alpha * v) / m; });
	auto eulerEquationSolve2([](double vi, double dt)->double { return (m * g - alpha * vi) / m * dt + vi; });
	std::function<double(double)> equationSolve2([](double t) { return m * g / alpha * (1. - exp(-alpha / m * t)); });

	std::cout << "For equation m*dT(t)/dt=m*g-a*v(t):" << std::endl;
	std::cout << "Euler error: " << solvertTester(Euler<double>(eulerEquationSolve2, dt, v0), equationSolve2, MNorm(), tEnd) << std::endl;
	std::cout << "RungeKutta error: " << solvertTester(RungeKutta<double>(rightSide2, dt, v0), equationSolve2, MNorm(), tEnd) << std::endl;

	return !true && !false;
}
