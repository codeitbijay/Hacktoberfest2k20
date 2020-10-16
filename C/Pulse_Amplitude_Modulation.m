clc;
close all;
clear all;

t = 0:0.0001:1;

a = input('Enter the amplitude of message signal = ');
f = input('Enter the frequency of message signal = ');

m = a*sin(2*pi*f*t);
subplot(5, 1, 1);
plot(t, m);
title('Message Signal');
xlabel('Time');
ylabel('Amplitude ');

c = square(2*pi*20*t,30);
c(find(c<0)) = 0;
subplot(5, 1, 3);
plot(t, c);
title('Carrier Wave');
xlabel('Time ');
ylabel('Amplitude ');

y = c.*m;
subplot(5, 1, 5)
plot(t,y)
title('PAM Wave');
xlabel('Time');
ylabel('Amplitude');
