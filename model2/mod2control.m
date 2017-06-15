function u_m=mod2control(u)
v=u(1:2);
v=v(:);
theta=u(3);
dtheta=u(4);
u1=u(5);
du1=u(6);

alpha=[-2*cos(theta)*dtheta*du1+u1*(dtheta^2)*sin(theta);
       -2*sin(theta)*dtheta*du1-u1*(dtheta^2)*cos(theta)];

beta=[-sin(theta) -u1*cos(theta);cos(theta) -u1*sin(theta)];
u_m=inv(beta)*(v-alpha);
end