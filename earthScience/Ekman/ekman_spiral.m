clear all, clc

Av = 0.02; %eddy viscosity for vertical mixing
tau = 1; %wind stress
rho = 1000; %density
dz = 1;
water_depth = 130;
phi = 15:1:75;
f = 2*(2*pi)/(24*60*60)*arrayfun(@(p)sin(deg2rad(p)), phi);

x = -water_depth:dz:0;
t = [0, 1, 2, 3, 4];

A = 1:size(phi, 2);
sol = arrayfun(@(T)pdepe(0,...
    @(x, t, u, dudx)pdefun(x,t,u,dudx, [Av, f(T), tau, rho]),...
    @(x)pdeic(x, [Av, f(T), tau, rho]),...
    @(xl,ul,xr,ur,t)pdebc(xl, ul, xr, ur, t, [Av, f(T), tau, rho]), x,t),...
    A, 'UniformOutput',false);


for i = A
    
    u1 = sol{i}(5,:,1);
    u2 = sol{i}(5,:,2);
    quiver3(zeros(size(x)),zeros(size(x)),x,u1,u2,zeros(size(x)),...
   '.','linewidth',1, 'MaxHeadSize', 0.000001);
    title(sprintf("위도 +%d 에서의 에크만 나선", phi(i)))
    xlabel('u');ylabel('v');
    zlabel('z')
    
    %hold on
    %dek=sqrt(2*Av/f(i));
    %s=tau*dek/rho/(1)/Av*exp((1+sqrt(-1))/dek*x);
    %v1=real(s);
    %v2=imag(s);
    %quiver3(zeros(size(x)),zeros(size(x)),x,v1,v2,zeros(size(x)),...
    %'--','linewidth',1, 'MaxHeadSize', 0.000001);
    %hold off
end


function [c, f, s] = pdefun(x, t, u, dudx, A)
c = [0; 0];
f = [A(1); A(1)].*dudx; %raynols
s = [A(2)*u(2); -A(2)*u(1)];  %corioli
end

function u0 = pdeic(x, A)
if x == 0
    u0 = [0.1; 0];
else
    u0 = [0 ; 0];
end
end

function [pl,ql,pr,qr] = pdebc(xl,ul,xr,ur,t, A)
pl = [ul(1); ul(2)];
ql = [0; 0];
pr = [ur(1); ur(2)];
qr = [-A(3)/(A(4)*(abs(A(1)*A(2)))^(0.5)); 0];
end