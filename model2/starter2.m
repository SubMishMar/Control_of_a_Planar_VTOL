% NOLCO project
thd0 = 0;
th0  =1;
zd0 = 0;
z0 = 1;
xd0= 0;
x0 = 1;
sim('model2_fixed')
% sim('model2') %everything works, need to change the delta manually in System block

%%%%%%%MAKE THE CORRECT GRAPHS!!!

% figure(1)
% plot(theta(:,1), theta(:,2)) %theta from simulink
% for i= 1:length(theta)
%    u11(i,1) = cos(theta(i,2)) ;
%    u21(i,1) = sin(theta(i,2))/0.001;
% end
% figure(2)
% plot(theta(:,1), u11(:,1)) %calculated u1
% figure(3)
% plot(theta(:,1), u21(:,1)) %calculated u2
% figure(4)
% plot(u1(:,1), (u1(:,2)-u11(:,1))) %error between simulink and calculated u1
% figure(5)
% plot(u2(:,1), (u2(:,2)-u21(:,1))) %error between simulink and calculated u2
