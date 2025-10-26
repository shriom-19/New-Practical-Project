clc; clear all; close all;
data_bits = 10000;
b = (rand(1, data_bits) > 0.5); % BPSK symbols
s = 2*b - 1;

SNRdB = 0:9;

for k = 1:length(SNRdB)
    y = s + awgn(s, SNRdB(k));
    error = 0;
    for c = 1:data_bits
        if ((y(c)<0) && (s(c)==1)) || ((y(c)>=0) && (s(c)==-1))
            error = error + 1;
        end
    end
    BER(k) = error / data_bits; % now BER is defined
end
% Replace zeros to avoid log(0)
BER(BER==0) = 1e-6;

figure;
semilogy(SNRdB, BER, 'r', 'LineWidth', 2);
hold on;

SNR = 10.^(SNRdB/10);
BER_thBPSK = (1/2)*erfc(sqrt(SNR));
BER_thBPSK(BER_thBPSK==0) = 1e-6; % avoid log(0)
semilogy(SNRdB, BER_thBPSK, 'k', 'LineWidth', 2);

BER_thQPSK = erfc(sqrt(SNR));
BER_thQPSK(BER_thQPSK==0) = 1e-6; % avoid log(0)
semilogy(SNRdB, BER_thQPSK, 'b', 'LineWidth', 2);

grid on;
xlabel('SNR (dB)');
ylabel('Bit Error Rate');
legend('Simulated BER', 'BPSK Theory', 'QPSK Theory');
