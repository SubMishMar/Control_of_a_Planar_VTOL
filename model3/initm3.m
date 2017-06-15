close all;
clc;
clear all;
%Coeff of sliding variable equation
a=9;
b=27;
c=27;
%Sliding Gains
kx=800;
kz=800;

sim('model3.slx');

x=h(:,1);
z=h(:,2);

u1=u(:,1);
u2=u(:,2);

s1=svar(:,1);
s2=svar(:,2);

figure(1)
subplot(3,1,1)
plot(t,x,'-r','LineWidth',1.5);
xlabel('time(s)')
ylabel('x(m)')
title('x(m) vs time(s)')
grid;
subplot(3,1,2)
plot(t,z,'-r','LineWidth',1.5);
xlabel('time(s)')
ylabel('z(m)')
title('z(m) vs time(s)')
grid;
subplot(3,1,3)
plot(t,theta,'-r','LineWidth',1.5);
xlabel('time(s)')
ylabel('\theta(rad)')
title('\theta(rad) vs time')
grid;

figure(2)
subplot(2,1,1)
plot(t,u1,'-r','LineWidth',1.5);
xlabel('time(s)')
ylabel('$u_1$ $(m.s^{-2})$','Interpreter','latex');
title('Control Input $u_1$ $(m.s^{-2})$ vs time(s)','Interpreter','latex');
grid;
subplot(2,1,2)
plot(t,u2,'-r','LineWidth',1.5);
xlabel('time(s)')
ylabel('$u_2$ $(rad.s^{-2})$','Interpreter','latex');
title('Control Input $u_2$ $(rad.s^{-2})$ vs time(s)','Interpreter','latex');
grid;

figure(3)
subplot(2,1,1)
plot(t,s1,'-r','LineWidth',1);
xlabel('time(s)');
ylabel('$s_1$','Interpreter','latex');
title('$s_1$ vs time(s)','Interpreter','latex');
grid;
subplot(2,1,2)
plot(t,s2,'-r','LineWidth',1);
xlabel('time(s)');
ylabel('$s_2$','Interpreter','latex');
title('$s_2$ vs time(s)','Interpreter','latex');
grid;