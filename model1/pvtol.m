function ddstate=pvtol(u)
u1=u(1);
u2=u(2);
theta=u(3);
eps=0.001;
ddx=-sin(theta)*u1+eps*u2*cos(theta);
ddz= cos(theta)*u1+eps*u2*sin(theta)-1;
ddstate=[ddx;ddz];
end