%% ENGR 113, Problem Set 07
% Authored by: Andres Choque
% Authored on: 11/21/2020

%% Problem 11.6

clear,clc,close all

% Problem Presentation
%{
The law of cosines for a triangle states that a^2 = b^2+c^2-2bc Cos A,
where a is the length of the side opposite the angle A, and b and c are the
lengths of the other sides.
a) use MATLAB to solve for b
b) suppose that A = 60, a = 5 m, and c = 2m. Determine b.
%}

% Pseudocode
% Initialize variables
% Perform calculations
% Display results

% Initialize variables
% Part a:
syms a b c A
eq1 = (b^2)+(c^2)-(2*b*c)*cos(A)==a^2;

% part b:
A_1 = (60*pi/180);
a_1 = 5;
c_1 = 2;

% Perform calculations
% Part a:
eq2 = solve(eq1,b);

% Part b:
eq3 = subs(eq2,A,A_1);
eq4 = subs(eq3,a,a_1);
eq5 = subs(eq4,c,c_1);
solu = double(eq5);

% Display results
fprintf('The equation in terms of b is: \n')
disp(eq2)
fprintf('The solution for b is %4.3f \n',solu)

%% Problem 11.11

close all 
clear 
clc

% Problem statement
%{
Use MATLAB to find all the values of x where the graph of y = 3^x-2x has a
horizontal tangent line.
%}

% Pseudocode
% Initialize variables
% Perform calculations
% Display results

% Initialize variables
syms x
eq1 = 3^x-2*x;
y = 3^x-2*x;
xpts = linspace(-2,2,500); 

% Perform calculations
dydx = diff(eq1);
solu = solve(dydx,x);

% Display results
plot(xpts,solu), grid minor, xlabel('(x)'), ylabel('(y)')
title('Graph of y = 3^x - 2x')

%% Problem 11.13

clear
close all
clc

% Problem set
%{
The surface area of a sphere of radius r is S = 4pir^2. Its volume is V =
4pir/3.
a) use MATLAB to find the expression for dS/dV.
b) a spherical ballon expands as air is pumped into it. What is the rate of
increase in the balloon's surface area with volume when its volume is 30
cubic inches?
%}

% Pseudocode
% Initialize variables
% Perform calculations
% Display results

% Initialize variables
% part a:
syms r S V
eq1 = 4*pi*r^2;
eq2 = (4*pi*r^3)/3;
eq1_1 = (45/(2*pi))^(1/3);
% part b:
V_1 = 30;

% Perform calculations
% part a:
eq_r = diff(eq1);
eq_r2 = diff(eq2);
dSdV = (eq_r)/(eq_r2);

% part b:
f = subs(dSdV,r,eq1_1);
solu = double(f);
% Display results
fprintf('for part a the expression is: ')
disp(dSdV)
fprintf('for part b the rate of increase is: %4.4f ',solu)

%% Problem 11.21

clear
close all
clc

% Problem presentation
%{
The equation for the voltage v(t) across a capacitor as a function of time
is v(t) = 1/c[int(0,t) i(t)dt+Q(o)] 
where i(t) is the applied current and Q(o) is the initial charge. Suppose 
that C = 10^-7F and Q(o) = 0. If the applied current is 
i(t) = 0.3 +0.1e^-5tsin(25pit), use MATLAB to compute and plot the voltage 
v(t) for 0<=t<=7 seconds.
%}


% Pseudocode
% Initialize variables
% Perform calculations
% Display results

% Initialize variables
syms t
eq1 = 0.3+0.1*exp(-5*t).*sin(25*pi*t);
C = 10^-7;
Qo = 0;
i_t = @(t)0.3+0.1*exp(-5*t).*sin(25*pi*t);
k = 1;

% Perform calculations
%itgrl = int(eq1,t);
v_t(1) = 0;
for t = 0:0.01:7
    v_t(k+1) = (1/C)*(integral(i_t,0,t(end))+Qo)+v_t(k);
    k = k+1;
end

% Display results
t = 0:0.01:7;
plot(t,v_t(2:end)), xlabel('Time (s)'), ylabel('Voltage V(t)')
grid minor
title('Voltage V(t) Across a Capacitor')


