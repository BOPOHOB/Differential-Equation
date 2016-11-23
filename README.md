# Differential-Equation
Сomparison between [Euler](https://en.wikipedia.org/wiki/Euler_method) and [classical Runge–Kutta](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) methods

Output example:
```
For equation dT(t)/dt=-gama(T(t)-T1) where T1 is constatnt:
for maximum norm:
        Euler deficiency: 0.00367726
        RungeKutta deficiency: 2.54463e-13
for Manhattan norm:
        Euler deficiency: 9.99334
        RungeKutta deficiency: 6.87646e-10

================

For equation m*dT(t)/dt=m*g-a*v(t):
for maximum norm:
        Euler deficiency: 0.00180268
        RungeKutta deficiency: 4.27036e-12
for Manhattan norm:
        Euler deficiency: 12.9512
        RungeKutta deficiency: 1.52095e-08
Для продолжения нажмите любую клавишу . . .
```
