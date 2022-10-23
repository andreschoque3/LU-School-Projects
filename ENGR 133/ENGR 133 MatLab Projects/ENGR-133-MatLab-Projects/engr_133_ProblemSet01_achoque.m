%% ENGR 133, Problem Set 01
% Authored by: Andres Choque
% Authored on: 9/11/2020

%% Problem 1.2

close all
clear
clc

% Problem presentation
%{
Suppose that x = 2 and y = 5. Use MATLAB to compute the following: 
a. yx^3/x - y
b. 3x/2y 
c. (3/2)xy 
d. x^5/(x^5 - 1).
%}

% Psuedocode
% Initialize variables
% Perform calculations
% Display the results

% Initialize variables
x = 2;
y = 5;

% Perform calculations
% Part a
a = (y*x^3)/(x - y);
% Part b
b = (3*x)/(2*y);
% Part c
c = (3/2)*x*y;
% Part d
d = (x^5)/((x^5) - 1);

% Display the results 
fprintf('The result for part a is %4.2f \n',a)
fprintf('The result for part b is %4.2f \n',b)
fprintf('The result for part c is %4.2f \n',c)
fprintf('The result for part d is %4.2f \n',d)


%% Problem 1.12

clear 
close all
clc

% Problem presentation
%{
Suppose that x = -7 - 5i and y = 4 + 3i. Use MATLAB to compute 
a. x+y 
b. xy 
c. x/y 
%}

% Psuedocode
% Initialize variables
% Perform calculations
% Display the results

% Initialize variables
x = -7 - 5i;
y = 4 + 3i;

% Perform calculations
% Part a:
a = x + y;
% Part b:
b = x*y;
% Part c:
c = x/y;

% display the results
fprintf('For part a the result is: ')
disp(a)
fprintf('For part b the result is: ')
disp(b)
fprintf('For part c the result is: ')
disp(c)

%% Problem 1.16

clear
close all
clc

% Problem presentation
%{
The ideal gas law relates the pressure P, volume V, absolute temperature T,
and the amount of gas n. the law is P = N R T / V where R is the gas constant. 
An engineer must design a large natural gas storage tank to be expandable 
to maintain the pressure constant at 2.2 atm. In December when the 
temperature is 4*F (-15*C), the volume of gas in the tank is 28,500 ft^3. 
What will the volume of the same quantity of gas be in July when the 
temperature is 88*F (31*C)? (Hint: Use the fact that n, R, and P are 
constant in this problem. Note also that K = *C + 273.2)
%}

% Psuedocode
% Initialize variables
% Perform calculations for volume V2
% Display results

% Initialize variables
T1 = -15 + 273.2;
T2 = 31 + 273.2;
V1 = 28500;

% Perform calculations for volume (V2)
V2 = V1*(T2/T1);

% display the results
fprintf('For 11.16 the volume of gas in (ft) during July is: %4.2f \n',V2)


%% Problem 1.26

clear
close all
clc

% Problem Presentation
%{
Use MATLAB to find the roots of 13x^3 + 182x^2 - 184x +2503 = 0.
%}

% Psuedocode
% Initialize variables
% Perform calculations
% Display results

% Initialize variables
w = [13, 182, - 184, 2503];

% Perform Calculations
roots = roots(w);

% Display results
fprintf('The roots of the equation is the following: \n')
disp(roots)

%% Problem 1.28

clear 
close all
clc

% Problem presentation
%{
Use MATLAB to plot the function u = 2 log(10)(60x+1) and v = 3 cos(6x) 
over the interval 0 <= x <= 2. Properly label the plot and each curve. 
The variables u and v represent speed in miles per hour; the variable x 
represents distance in miles
%}

% Psuedocode
% Initialize variables
% Display results

% Initialize variables
x = 0:0.01:2;
u = 2*log10(60*x + 1);
v = 3*cos(6*x);

% Display results
plot(x,u,x,v), xlabel('Distance (mi)')
ylabel('Speed (mi/h)')
title('The Function U and V Determined Through Speed in Miles')
grid minor
