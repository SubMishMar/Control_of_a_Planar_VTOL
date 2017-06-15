function u_m=mod1control(u)
v=u(1:2);
v=v(:);
theta=u(3);
alpha=[0;-1];
eps=0.001;
beta=[-sin(theta) eps*cos(theta);
       cos(theta) eps*sin(theta)];
u_m=inv(beta)*(v-alpha);
end