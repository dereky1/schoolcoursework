%derek yang
%63118832

I = rgb2gray(imread('C:\Users\Derek\Pictures\wallpaper\android tiger.jpg'));
I = im2double(I);
%imshow(I)

A = ones(100,100);
A(1:100,1:100) = I(620:719,1130:1229);
%imshow(A)

%a
x = ones(1,10000);
x(1:10000) = A;
plot(sort(x));

%b
histogram(x,32);

%c
t = .5;
gt = find(A>t);
lt = find(A<t);
B = zeros(100,100);
B(gt) = 1;
B(lt) = 0;
imshow(B)

%d
m = mean(x);
C = zeros(100,100);
C(1:100,1:100) = A(1:100,1:100)-m;
ze = find(C<0);
C(ze) = 0;
imshow(C)

%e
y = (1:6);
z = reshape(y,3,2);

%f
mins = min(A);
x = min(mins);
pos = find(A==x);
[r,c] = ind2sub(size(A),pos(1));

%g
v = [1 8 8 2 1 3 9 8];
number = length(unique(v));




