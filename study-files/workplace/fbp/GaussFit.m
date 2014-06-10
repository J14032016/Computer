
x=[50  25  13  6  3  0.5];
y=[1.5  11  30  55  70  88];
b0=[0,1];
[b,r,j]=nlinfit(x,y, 'ep',b0);
[yp,d]=nlpredci ('ep',x,b,r,j);
ci=nlparci(b,r,j);
nlintool(x,y, 'ep',b0);

%{
x=[3.46  7.33  9.47  10.48  11.19  11.79  12.78  20.50];
y=[10.69  56.84  76.89  82.15  84.70  86.32  88.45  100];
% x=x';
b0=[0.2  0  -0.4  -0.1  5];
[b,r,j]=nlinfit(x,y, 'ep',b0);
[yp,d]=nlpredci ('ep',x,b,r,j);
ci=nlparci(b,r,j);
nlintool(x,y, 'ep',b0);
%}