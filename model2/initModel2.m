% clear all;
% clc;
% k11=1;
% k12=4;
% k13=6;
% k14=4;
% 
% k21=1;
% k22=4;
% k23=6;
% k24=4;
% 
% x0=0;
% z0=1.5;
% theta0=0.7;

% sim('model2');
% 
subplot(3,2,1);
plot(t,x);
xlabel('t-->');
ylabel('X-->');
title('X vs t');
grid
subplot(3,2,2);
plot(t,z);
xlabel('t-->');
ylabel('Z-->');
title('Z vs t');
grid;
subplot(3,2,3);
plot(t,u1);
xlabel('t-->');
ylabel('u1-->');
title('u1 vs t');
grid;
subplot(3,2,4);
plot(t,u2);
xlabel('t-->');
ylabel('u2-->');
title('u2 vs t');
grid;
subplot(3,2,5);
plot(t,theta);
xlabel('t-->');
ylabel('theta-->');
title('theta vs t');
grid;