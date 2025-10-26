%% inputs: 7 , 4 , [101], [1000111]




clc; clear; close all;

%% --- Input code parameters ---
n = input('Enter codeword length n: ');
k = input('Enter number of data bits k: ');
m = n - k; % number of parity bits

%% --- Generator Polynomial (Cyclic Code) ---
G = cyclpoly(n, k, 'max');  % Maximum-length cyclic polynomial
disp('Generator polynomial:'); poly2sym(G)

%% --- Generate all possible data messages ---
data = de2bi(0:2^k-1, k, 'left-msb'); % all messages
disp('Data messages:'); disp(data)

%% --- Encode messages using cyclic code ---
codewords = zeros(size(data,1), n);
for i = 1:size(data,1)
    msg_poly = [data(i,:) zeros(1, n-k)];  % append m zeros
    remainder = mod(conv(msg_poly, 1), 2);  % init
    % Perform modulo-2 division
    temp = msg_poly;
    for j = 1:k
        if temp(j) == 1
            temp(j:j+length(G)-1) = mod(temp(j:j+length(G)-1) + G, 2);
        end
    end
    remainder = temp(end-m+1:end);
    codewords(i,:) = [data(i,:) remainder];  % final codeword
end
disp('Encoded codewords:'); disp(codewords)

%% --- Hamming code parity-check matrix ---
if n == 2^m - 1
    H = hammgen(m);  % only valid for Hamming code
    syndrome_table = syndtable(H);
else
    warning('Hamming code correction is valid only if n = 2^m - 1');
    H = [];
    syndrome_table = [];
end

%% --- Input a received codeword manually ---
fprintf('\nEnter received codeword (length %d) as a row vector, e.g., [1 0 1 ...]\n', n);
recd = input('Received codeword: ');

%% --- Compute syndrome & correct error (for Hamming only) ---
if ~isempty(H)
    syndrome = mod(recd * H', 2);
    syndrome_dec = bi2de(syndrome, 'left-msb');
    error_pattern = syndrome_table(1 + syndrome_dec, :);
    corrected = mod(recd + error_pattern, 2);
else
    warning('Skipping Hamming error correction.');
    syndrome = [];
    error_pattern = [];
    corrected = recd;
end

%% --- Display results ---
fprintf('\nReceived codeword: %s\n', mat2str(recd));
if ~isempty(syndrome)
    fprintf('Syndrome: %s\n', mat2str(syndrome));
    fprintf('Error pattern: %s\n', mat2str(error_pattern));
end
fprintf('Corrected codeword: %s\n', mat2str(corrected));

