%inputs: 5 
%0.1 ,0.15 ,0.19 , 0.4 , 0.16




clc;
clear all;
close all;
code_length=0;
x=input('Enter number of symbols: ');
symbols = 1:x;
p = zeros(1,x);
for i=1:x
    p(i) = input(['Enter probability of symbol ',num2str(i), ': ']);
end
p = sort(p,'descend');

HX = 0;
Total_code_len = 0; % initialize accumulator
for m=1:x
    dist = huffmandict(symbols, p);
    hcode = huffmanenco(symbols(m), dist); % encode actual symbol
    dsig = huffmandeco(hcode, dist);
    
    HX = HX + p(m) * ( -log2(p(m)) ); % entropy
    code_length = length(hcode); % length of codeword
    Total_code_len = Total_code_len + p(m)*code_length; % accumulate
end
 
avglen = Total_code_len; % final average length
fprintf('Entropy(H) = %.4f bits \\n', HX);
fprintf('Average Code Length = %.4f bits\\n', avglen);
fprintf('Efficiency = %.2f %%\\n', (HX/avglen)*100);
