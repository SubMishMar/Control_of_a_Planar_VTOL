k12=25;
k11=10;

k22=25;
k21=10;

x0=2;
z0=2.3;
theta0=0.5;

 sim('model1');

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