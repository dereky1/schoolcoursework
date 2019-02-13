%mygradient(imresize(im2double(rgb2gray(imread('C:\Users\Derek\Desktop\CS116\HW4\signtest\test2.jpg'))), 0.5)

function [mag,ori] = mygradient(I)
%
% compute image gradient magnitude and orientation at each pixel
%
%
assert(ndims(I)==2,'input image should be grayscale');

F = [-1,0,1];
F2 = [-1;0;1];

dx = imfilter(I,F,'replicate');
dy = imfilter(I,F2,'replicate');

mag = sqrt(dx.^2 + dy.^2);
ori = atan(dy./dx);
mag(isnan(ori)) = 0;
ori(isnan(ori)) = 0;

assert(all(size(mag)==size(I)),'gradient magnitudes should be same size as input image');
assert(all(size(ori)==size(I)),'gradient orientations should be same size as input image');


% figure(12);
% title('Mag');
% colormap jet;
% colorbar;
% imagesc(mag);
% 
% figure(13);
% title('Ori');
% colormap hsv;
% colorbar;
% imagesc(ori)

