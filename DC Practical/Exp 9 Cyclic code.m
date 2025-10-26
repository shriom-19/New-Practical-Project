%Inputs: 
%[1000110;0100011;0010111;0001101]
%[0111101]


clc;
clear all;

disp('generated matrix')
g = input('enter the generator matrix: ');

[k,n] = size(g);
disp('the order of the linear block code for given generator matrix is:');
disp([n n-k]);

% --- Parity-check matrix ---
P = g(:, k+1:end);   % Extract P assuming systematic G
h = [P' eye(n-k)];
disp('Parity-check matrix H:');
disp(h);

% --- Generate all possible codewords ---
data = de2bi(0:2^k-1, k, 'left-msb');
c = mod(data*g, 2);
disp('the possible codewords are:');
disp(c);

% --- Minimum Hamming distance ---
weight = sum(c,2);
d_min = min(weight(weight>0));
disp(['the minimum hamming distance dmin for given block code= ', num2str(d_min)]);

% --- Received codeword ---
p = input('enter the received code word: ');

% --- Syndrome ---
s = mod(p*h',2);
disp('Syndrome of the given codeword:');
disp(s);

% --- Single-bit error detection ---
error_pos = -1;
for i = 1:n
    if isequal(h(:,i), s')   % Compare syndrome with H columns
        error_pos = i;
        break;
    end
end

if error_pos ~= -1
    disp(['the error is in bit: ', num2str(error_pos)]);
    p(error_pos) = mod(p(error_pos)+1,2); % Correct the error
else
    if any(s)
        disp('Error detected but cannot correct (multiple bits).');
    else
        disp('No error detected.');
    end
end

disp('the corrected codeword is:');
disp(p);


