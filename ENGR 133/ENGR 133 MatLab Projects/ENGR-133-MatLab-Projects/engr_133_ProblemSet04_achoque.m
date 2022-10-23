%% ENGR 133, Problem Set 04
% Authored by: Andres Choque
% Authored on: 10/10/2020

%% Problem 3.9

clear, close all, clc

% Problem Presentation
%{
An object thrown vertically with a speed Vo reaches a height h at time t, where
h = Vot - 1/2gt^2. 
Write and test a function that computes the time t required to
reach a specified height h, for a given value of Vo. The function's inputs should
be h, Vo, and g. Test your function for the case where h = 100m, Vo = 50 m/s, and
g = 9.81 m/s^2. Interpret both answers.
%}

% Pseudocode
% Initialize variables
% Create the function in .M file
% Perfrom Calculatons
% Display results

% Initialize variables
h = 100;
Vo = 50;
g = 9.81;

% Create the function in .M file
function [T1,T2] = time_reaching_h(h, Vo, g)
  % Computes time t to reach a specified height h. with inital speed Vo
  T = roots([0.5*g, -Vo, h])
end
T = roots([0.5*g, -Vo, h]);

% Perform Calculations
T1 = min(T);
T2 = max(T);

% Display results
fprintf('For Problem 3.9 it takes this amount of time to ascend: %2.0f\n\n')
disp(T1)
fprintf('For Problem 3.9 it takes this amount of time to descend: %2.0f\n\n')
disp(T2)

%% Problem 3.16

clear, close all, clc

% Problem Presentation
%{
The volume V and paper surface area A of a conical paper cup are given by 
V = 1/3*pi*r^2*h and A = pi*r*sqrt(r^2+h^2) 
where r is the radius of the base of the cone. 

a. by eliminating h, obtain the expression for A as a function of r 
and V. 
b. create a user-defined function that accepts R as the only argument and 
computes A for a given value of V. Declare V to be global within the function.
c. For V = 10 in^3, use the function with the fminbnd function to compute the
value of r that minimizes the area A. 

What is the corresponding value of the height h? Investigate the sensitivity of 
the solution by plotting A versus r. 
How much can R vary about its optimal value before the area increases 10 percent
above its minimum value?
%}

% Pseudocode
% Initialize variables
% create a function
% Determine the corresponding value of height
% Display results

% Initialize variables
% A = pi*r*sqrt(r^2+(9*v^2)/(pi^2*r^4)
% this is a derived function of volume in terms of h 
% then this function is plugged into h for the area function


% Create a function
%function A=conic_area(r)
%  global V
%  A = pi.*r.*sqrt(r.^2*(9*V^2)./pi^2.*r.^4))
%end

% Determine the corresponding value of height
%r_opt = fminbnd(@conic_area,0,10) % represents r that minimizes area
%min_Area = conic_area(r_opt) % represents the minimum area

% Display results
%r = 0:0.1:10;
%A = conic_area(r)
%plot(r,A), grid minor
%xlabel('radius (in)')
%ylabel('Area (in^2)')
%title('The Value of Radius that Minimizes the Area')
 
%% Problem 3.19

clear, close all, clc

% Problem Presentation
%{
Create a function called savings_balance that determines the balance in a
savings account at the end of every year for the first n years, where n is an 
input. the account has an initial investment A(to be provided as input for
example, enter $10,000 as 10000) and an annually compounded interest rate of r%
(to be provided as input; for example, enter 3.5% as 3.5). 
Display the information screen in a table in which the first column is Year 
and the second is Balance($). 
(Test case: n =10, A=10000, r =3.5. After 10 years the balance is $14,105.99.)
with an initial investment of A and interest rate r, the balance B after n years 
is given by: B = A(1+r/100)^n
%}

% Psuedocode
% Initialize variables
% create a function
% Perform the calculations
% Display results

% Initialize variables
n = 10;
A = 10000;
r = 3.5;

% create a function
function B = savings_balance(n, A, r)
  %determines the balance in a savings account at the end of every year
  B = A*(1+r/100)^n;
end

% Perform the calculations
Balance=B=savings_balance(n, A, r);
Years= n;
% Display results
Table = [Years' Balance'];
disp('The Balance in a Savings Account at the End of Every n Years')
disp('')
disp('      Years      Balance($)') %Displays the number of years and balance in $ value
disp(Table)

%% Problem 4.10

clear, close all, clc

% Problem Presentation
%{
The arrays price_A, price_B, and price_C given below contain the price in dollars
of three stocks over 10 days.
a. Use MATLAB to determine how many days the price of stock A was above both the 
price of stock B and the price of stock C. 
b. Use MATLAB to determine how many days the price of stock A was above either 
the price of stock B or the price of stock C.
c. Use MATLAB to determine how many days the price of stock A was above either
the price of stock B or the price of stock C, but not both.

price_A = [19, 18, 22, 21, 25, 19, 17, 21, 27, 29]
price_B = [22, 17, 20, 19, 24, 18, 16, 25, 28, 27]
price_C = [17, 13, 22, 23, 19, 17, 20, 21, 24, 28]
%}

% Pseudocode
% Initialize variables
% perfrom the calculations
% Display the resutls

% Initialize variables
price_A = [19, 18, 22, 21, 25, 19, 17, 21, 27, 29];
price_B = [22, 17, 20, 19, 24, 18, 16, 25, 28, 27];
price_C = [17, 13, 22, 23, 19, 17, 20, 21, 24, 28];

% Perform the calculations
above_price_B_and_C = length(find(price_A > price_B & price_A > price_C));
above_price_B_or_C = length(find(price_A > price_B | price_A > price_C));
above_either_B_or_C = length(find(xor(price_A > price_B,price_A > price_C)));
  
% Display the resutls
fprintf('Stock A price was above both price B and C for %2.0f days.\n\n',above_price_B_and_C)
fprintf('Stock A price was above both price B or C for %2.0f days.\n\n',above_price_B_or_C)
fprintf('Stock A price was above either price B or C for %2.0f days.\n\n',above_either_B_or_C)
 
%% Problem 4.12

clear, close all, clc

% Problem Presentation
%{
The height and speed of a projectile (such as a thrown ball) launched with a 
speed of Vo at an angle A to the horizontal are given by:

h(t) = Vot*sin(A) - 0.5*g(t)^2
v(t) = sqrt(Vo^2-2Vo*gt*sin(A)+g^2*t^2)

where g is the acceleration due to gravity. The projectile will strike the ground
when h(t)=0, which gives the time to hit t_hit =2(Vo/g)*sin(A).
Suppose that A = 30*, Vo = 40 m/s, and g = 9.81m/s^2. Use the MATLAB relational
and logical operators to find the times when:
a. the height is no less than 15 m.
b. the height is no less than 15 m and the speed is simultaneously no greater 
than 36 m/s.
c. The height is less than 5 m or the speed is greater than 35 m/s.
%}

% Pseudocode
% Initialize varibles
% Perform the calculations
% Display the results


% Initialize varibles
Vo = 40;
A = 30*pi/180;
g = 9.81;
t_hit = 2*(Vo/g)*sin(A);
t = 0:t_hit/100:t_hit;
h = Vo.*t.*sin(A)-0.5.*g.*t.^2;
v = sqrt(Vo.^2-2.*Vo.*g.*t.*sin(A)+(g.^2).*(t.^2));

% Perform the calculations
% Part a
x = find(h>=15);
t1_a = min(t(x));
t2_a = max(t(x));
TA = [num2str(t1_a),' <= t <= ',num2str(t2_a)]; %Time interval for a

% Part b
y = find(h>=15 & v<=36);
t1_b = min(t(y));
t2_b = max(t(y));
TB = [num2str(t1_b),' <= t <= ',num2str(t2_b)]; %Time interval for b

% Part c
z = find(h < 5 & v > 35);
w = length(z)/2;
t1_c = min(t(z));
t2_c = min(t(w));
t3_c = max(t(w));
t4_c = max(t(z));
TC = [num2str(t1_c),' <= t <= ',num2str(t2_c),' and ',num2str(t3_c),' <= t <= ',num2str(t4_c)];
%Time interval for c

% Display the results
fprintf('The time interval in which the height is no less than 15m: %2.0f\n\n')
disp(TA)
fprintf('the time interval in which the height is no less than 15 m and the speed is no greater than 36 m/s: %2.0f\n\n')
disp(TB)
fprintf('The time interval in which the height is less than 5 m or the speed is greater than 35 m/s: %2.0f\n\n')
disp(TC)




