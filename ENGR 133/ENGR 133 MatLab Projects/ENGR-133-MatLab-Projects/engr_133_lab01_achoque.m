%% ENGR 133, Lab-01
% Authored by: Andres Choque
% Authored on: 9/5/2020

%% Exercise TI1.1-4
 
close all
clear
clc
 
% Initialize Variables
x = -5 + 9i;
y = 6 - 2i;
 
% Calculate the sum
sum = x + y
 
% Calculate the product
product = x*y
 
% Calculate the ratio
ratio = x/y
 
%% Exercise TI1.3-3
 
% Initialize Variables
x1 = 0:0.01:10;
y1 = 3*x1.^2 + 2;

% Generate plot
plot(x1,y1)  