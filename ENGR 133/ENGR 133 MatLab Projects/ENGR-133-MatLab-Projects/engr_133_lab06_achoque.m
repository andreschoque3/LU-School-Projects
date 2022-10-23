%% ENGR 133, Lab 06
% Authored by: Andres Choque
% Authored on: 10/29/20

%% Problem 1

close all
clear
clc

% Problem statement
%{
Given the depths of water at various distances from the shore of a river,
compute the cross-sectional area.
%}

% Initialize variables
distance = [0:40:440];
depth = [0, 40, 96, 140, 147, 121, 117, 139, 140, 62, 18, 0];

% Perform calculations
area = trapz(distance, depth);

% Display results
fprintf('The cross-sectional area is %5.0f feet.\n\n', area)

%% Problem 2

close all
clear 
clc

% Problem statement
%{ Begin to familiarize with calculus functions
%}

% Intialize variables
T = 48000; %Thrust in Newtons
mo = 2200; %Initial mass in kilograms
r = 0.8; %Fuel fraction of mass
b = 40; %Burn time in seconds
g = 9.81; %Gravitational constant
to = 0;
tf = b;

% Perform calculations
dv = @(t) 48000./(2200*(1-0.8*t/40))-9.81;
v = integral(dv, to, tf);

% Display results
fprintf('The velocity at %2.0f seconds is %5.1f m/s.\n\n',b,v)
