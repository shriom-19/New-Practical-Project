clc;
clear all;
close all;
x = -6:0.1:6;

% ----------------- CASE 1 -----------------
m = -1; sd = 1;
y1 = normpdf(x, m, sd);

% ----------------- CASE 2 -----------------
m = 0; sd = 1;
y2 = normpdf(x, m, sd);

% ----------------- CASE 3 -----------------
m = 1; sd = 1;
y3 = normpdf(x, m, sd);

% ----------------- Single Figure with 3 Subplots -----------------
figure;

% Left Plot
subplot(1,3,1);
plot(x, y1, 'b', 'LineWidth', 2);
title('CASE-1: mean = -1, std dev = 1');
xlabel('x values ->'); ylabel('PDF ->');
grid on;

% Middle Plot
subplot(1,3,2);
plot(x, y2, 'r', 'LineWidth', 2);
title('CASE-2: mean = 0, std dev = 1');
xlabel('x values ->'); ylabel('PDF ->');
grid on;

% Right Plot
subplot(1,3,3);
plot(x, y3, 'g', 'LineWidth', 2);
title('CASE-3: mean = 1, std dev = 1');
xlabel('x values ->'); ylabel('PDF ->');
grid on;
