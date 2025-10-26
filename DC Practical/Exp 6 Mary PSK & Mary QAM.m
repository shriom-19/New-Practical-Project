% Put inputs : 4


clc
clear all;
close all;
N=input('Enter number of bits to be grouped: ');
M=2^N;
x=[0:M-1];
k=1;
OFF=0;
z=pskmod(x,M);
scatterplot(z,k,OFF,'r+');
title('M-ary PSK');
y=qammod(x,M);
scatterplot(y,k,OFF,'b*');
title('M-QAM');
