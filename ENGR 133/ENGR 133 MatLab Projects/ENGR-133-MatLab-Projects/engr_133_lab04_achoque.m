%% ENGR 133, Lab-04
% Authored by: Andres Choque
% Authored on: 10/6/2020

%% Problem 1

close all
clear
clc

% Problem Presentation
%{
We are asked to write a function that accepts a temperature expressed in degrees
Fahrenheit (oF) and computes the corresponding value in degrees Celsius (oC).
We are further instructed to test our functions. 
%}

% Function file destination

%{
function y = tempF2C(x)
  % Converts from Fahrenheit to Celsius
y = (5/9)*(x-32);
endfunction
%}

function y = tempF2C(x)
  % Converts from Fahrenheit to Celsius
y = (5/9)*(x-32);
endfunction

% Initialize Variables
test_temps_F = [-460 32 212]; % Test temperatures defined at key known points

% Perform calculations
test_results_C = tempF2C(test_temps_F); % Calls function with test points

% Display results
fprintf('The test temperatures are:\n\n')
disp(test_temps_F)
fprintf('\n\nThe computed temperature are:\n\n')
disp(test_results_C)

%% Problem 2

close all
clear 
clc

% Problem Presentation
%{
We are asked to write a function that accepts a temperature expressed in degrees
Fahrenheit (oF) and computes the corresponding value in degrees Celsius (oC). We
are further instructed to test our functions.
%}

% Function file destination
tempF2C = @(x) (5/9)*(x-32); % Converts from Fahrenheit to Celsius

% Initialize Variables
test_temps_F = [-460 32 212]; % Test temperatures defined at key known points

% Perform calculations
test_results_C = tempF2C(test_temps_F); 

% Display results
Table = [test_temps_F' test_results_C']; % Prepare data for display
disp('Table of Temperature Conversion') % Display data table
disp('') % Insert blank line
disp('  Fahrenheit   Celsius') % Display table headings
disp(Table) % Display table contents  

%% Problem 3

close all
clear 
clc

% Problem Presentation
%{
We are asked to use the fminbnd function to find the values of R and L of the 
figure provided that will minimize the total cost of enclosing the area with 
fence.
%}

% Function file definition

%{
function Ct = fence(R)
A = 2000; % area to be enclosed (square feet)
Cs = 40; % cost of a straight fence per foot
Cc = 50; % cost of curved fence per foot
L = (A-0.5*pi*R.^2)./(2*R); % length as a function of A & R
Ct = Cs*(2*R+2*L)+Cc*pi*R; % Cost calculation
end
%}
function Ct = fence(R)
A = 2000; % area to be enclosed (square feet)
Cs = 40; % cost of a straight fence per foot
Cc = 50; % cost of curved fence per foot
L = (A-0.5*pi*R.^2)./(2*R); % length as a function of A & R
Ct = Cs*(2*R+2*L)+Cc*pi*R; % Cost calculation
end

%  Initialize Variables
global A % Makes variable A available in both the function & main script
optimum_R = fminbnd(@fence,0,2000); % finds R between 0-100 that minimize Ct

% Perform calculations
min_cost = fence(optimum_R); %Returns minimum cost at optimum R
optimum_L = (2000-0.5*pi*optimum_R.^2)./(2*optimum_R); % Corresponding to L to R

% Display results
fprintf('The optimum value of R is: %5.2f feet.\n\n',optimum_R)
fprintf('The corresponding value of L is: %5.2f feet.\n\n',optimum_L)
fprintf('The resulting minimum cost is: $%5.2f.\n\n',min_cost)


%% Problem 4

close all
clear 
clc

% Problem Presentation
%{
We are given the history of daily prices for two stocks and are asked to
determine how many days the price of stock A was above that of stock B. Our 
Peudocode for solving this problem is:
  --compare each price daily to see if stock A is higher than stock B
  --create a list of the days where this condition is true
  --count how many days are in our list
  --Display the results
%}

% Initialize variables
price_A = [19,18,22,21,25,19,17,21,27,29]; % Data for stock A
price_B = [22,17,20,19,24,18,16,25,28,27]; % Datd for stock B

% Perform calculations
total_days = length(price_A); % total days of data
comp_days = find(price_A>price_B); % days stock A is greater than stock B
num_days = length(comp_days); % count of days A>B

% Display results
fprintf('Stock A price was compared to stock B for %2.0f days.\n\n',total_days)
fprintf('Stock A price exceeded stock B price on %2.0f days.\n\n',num_days) 

 
