clc;
clear;
%% ax+by+cz=d
%% ex+fy+gz=h
%% ix+jy+kz=l

%% taking coefficients of the elements in the equation from user

a=input('Enter the coefficient of the x element in the first equation: ');
b=input('Enter the coefficient of the y element in the first equation: ');
c=input('Enter the coefficient of the z element in the first equation: ');
d=input('Enter the result of the first equation: ');

e=input('Enter the coefficient of the x element in the second equation: ');
f=input('Enter the coefficient of the y element in the second equation: ');
g=input('Enter the coefficient of the z element in the second equation: ');
h=input('Enter the result of the second equation: ');

i=input('Enter the coefficient of the x element in the third equation: ');
j=input('Enter the coefficient of the y element in the third equation: ');
k=input('Enter the coefficient of the z element in the third equation: ');
l=input('Enter the result of the third equation: ');

%%              FOR JACOBI METHOD

%%          FIRST ITERATION

%%  Initial values are x0,y0,z0=(0,0,0)   (k=0)

x_0= 0;
y_0 = 0;
z_0 = 0;

x_1 = (d - b*y_0 - c*z_0) / a;
y_1 = (h - e*x_0 - g*z_0) / f;
z_1 = (l - i*x_0 - j*y_0) / k;

%%For show on the grap assign to the vector(matrice 1x1)
A = [x_1];
B = [y_1];
C = [z_1];

%%segmenting to figure
subplot(2,3,1)

%%ploting the value's graph,for 'b' is colored the graph
stem3(A,B,C,'b')

%%named axis
grid on

xlabel('x axis');
ylabel ('y axis');
zlabel ('z axis');

title('Jacobi first iteration')

%%          SECOND ITERATION

%%  Initial values are x_1 , y_1 , z_1     (k=1) 

x_2 = (d - b*y_1 - c*z_1) / a;
y_2 = (h - e*x_1 - g*z_1) / f;
z_2 = (l - i*x_1 - j*y_1) / k;

%%For show on the grap assign to the vector(matrice 1x1)

E = [x_2];
F = [y_2];
G = [z_2];

%%segmenting to figure
subplot(2,3,2)
    
%%ploting the value's graph,for 'r' is colored the graph
stem3(A,B,C,'r')

%%named axis
grid on

xlabel('x axis');
ylabel ('y axis');
zlabel ('z axis');

title('Jacobi second iteration')

%%      THIRD ITERATION
%%  Initial values are x_2 , y_2 , z_2     (k=2) 

x_3 = (d - b*y_2 - c*z_2) / a;
y_3 = (h - e*x_2 - g*z_2) / f;
z_3 = (l - i*x_2 - j*y_2) / k;

%%For show on the grap assign to the vector(matrice 1x1)

I = [x_3];
J = [y_3];
K = [z_3];

%%segmenting to figure
subplot(2,3,3)
    
%%ploting the value's graph,for 'r' is colored the graph
stem3(A,B,C,'g')

%%named axis
grid on

xlabel('x axis');
ylabel ('y axis');
zlabel ('z axis');

title('Jacobi third iteration')

%%          FOR GAUSS SEIDEL METHOD
%%      FIRST ITERATION
%%  Initial values are x__0 , y__0 , z__0     (k=0)

x__0 = 0;
y__0 = 0;
z__0 = 0;

x__1 = (d - b*y__0 - c*z__0) / a;
y__1 = (h - e*x__1 - g*z__0) / f;
z__1 = (l - i*x__1 - j*y__1) / k;

%%For show on the grap assign to the vector(matrice 1x1)

AA = [x__1];
BB = [y__1];
CC = [z__1];

%%segmenting to figure
subplot(2,3,4)

%%ploting the value's graph,for 'b' is colored the graph
stem3(AA,BB,CC,'b')

%%named axis
grid on

xlabel('x axis');
ylabel ('y axis');
zlabel ('z axis');

title('Gauss Seidel first iteration')

%%      SECOND ITERATION 
%%  Initial values are x__1 , y__1 , z__1


x__2 = (d - b*y__1 - c*z__1) / a;
y__2 = (h - e*x__2 - g*z__1) / f;
z__2 = (l - i*x__2 - j*y__2) / k;

%%For show on the grap assign to the vector(matrice 1x1)

EE = [x__2];
FF = [y__2];
GG = [z__2];

%%segmenting to figure
subplot(2,3,5)

%%ploting the value's graph,for 'b' is colored the graph
stem3(EE,FF,GG,'r')

%%named axis
grid on

xlabel('x axis');
ylabel ('y axis');
zlabel ('z axis');

title('Gauss Seidel second iteration')

%%      THIRD ITERATION
%%  Initial values are x__2 , y__2 , z__2

x__3 = (d - b*y__2 - c*z__2) / a;
y__3 = (h - e*x__3 - g*z__2) / f;
z__3 = (l - i*x__3 - j*y__3) / k;

%%For show on the grap assign to the vector(matrice 1x1)

II = [x__3];
JJ = [y__3];
KK = [z__3];

%%segmenting to figure
subplot(2,3,6)

%%ploting the value's graph,for 'b' is colored the graph
stem3(II,JJ,KK,'g')

%%named axis
grid on

xlabel('x axis');
ylabel ('y axis');
zlabel ('z axis');

title('Gauss Seidel third iteration')
