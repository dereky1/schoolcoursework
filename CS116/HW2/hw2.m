% load in images

% you may want to replace these with absolute paths to where you stored the images
%atrium
%imnames = {'C:\Users\Derek\Desktop\CS116\HW2\atrium\IMG_1347.JPG','C:\Users\Derek\Desktop\CS116\HW2\atrium\IMG_1348.JPG','C:\Users\Derek\Desktop\CS116\HW2\atrium\IMG_1349.JPG'};
%window
%imnames = {'C:\Users\Derek\Desktop\CS116\HW2\window\IMG_1341.JPG','C:\Users\Derek\Desktop\CS116\HW2\window\IMG_1342.JPG','C:\Users\Derek\Desktop\CS116\HW2\window\IMG_1343.JPG','C:\Users\Derek\Desktop\CS116\HW2\window\IMG_1344.JPG','C:\Users\Derek\Desktop\CS116\HW2\window\IMG_1345.JPG'};
%custom1
%imnames = {'C:\Users\Derek\Desktop\CS116\HW2\custom1\one.JPG','C:\Users\Derek\Desktop\CS116\HW2\custom1\two.JPG','C:\Users\Derek\Desktop\CS116\HW2\custom1\three.JPG'};
%custom2
imnames = {'C:\Users\Derek\Desktop\CS116\HW2\custom2\one.JPG','C:\Users\Derek\Desktop\CS116\HW2\custom2\two.JPG','C:\Users\Derek\Desktop\CS116\HW2\custom2\three.JPG'};
nimages = length(imnames);
baseim = 1; %index of the central "base" image which

for i = 1:nimages
  ims{i} = im2double(imread(imnames{i}));
  %resize the image to 1/4 resolution so things run quicker while debugging your code
  ims{i} = imresize(ims{i},0.25);  
  ims_gray{i} = rgb2gray(ims{i});
  [h(i),w(i),~] = size(ims{i});
end

%get corresponding points between each image and the central base image
pixel = [];
for i = 1:nimages
   if (i ~= baseim)
     %run interactive select tool to click corresponding points on base and non-base image
     [moving, fixed] = cpselect(ims{baseim},ims{i},'Wait',true);
     pixel = [pixel, [moving, fixed]];
   end
end

%save('hw2_var.mat', 'pixel');
%load('hw2_var.mat', 'pixel');

%PLOT OF IMG 1 & IMG 2
% 
% subplot(2,1,1); 
% imshow(ims{1});
% hold on;
% plot(pixel(1,1),pixel(1,2),'r*',pixel(2,1),pixel(2,2),'b*',pixel(3,1),pixel(3,2),'g*',pixel(4,1),pixel(4,2),'y*');
% subplot(2,1,2);
% imshow(ims{2});
% hold on;
% plot(pixel(1,3),pixel(1,4),'r*',pixel(2,3),pixel(2,4),'b*',pixel(3,3),pixel(3,4),'g*',pixel(4,3),pixel(4,4),'y*');

%PLOT OF IMG 1 & IMG 3
% 
% subplot(2,1,1); 
% imshow(ims{1});
% hold on;
% plot(pixel(1,5),pixel(1,6),'r*',pixel(2,5),pixel(2,6),'b*',pixel(3,5),pixel(3,6),'g*',pixel(4,5),pixel(4,6),'y*');
% subplot(2,1,2);
% imshow(ims{3});
% hold on;
% plot(pixel(1,7),pixel(1,8),'r*',pixel(2,7),pixel(2,8),'b*',pixel(3,7),pixel(3,8),'g*',pixel(4,7),pixel(4,8),'y*');


% estimate homography for each image

for i = 1:nimages
   if (i ~= baseim)
     Hi{i} = computeHomography(pixel(1:4,3+((i-2)*4)), pixel(1:4,4+((i-2)*4)),pixel(1:4,1+((i-2)*4)),pixel(1:4,2+((i-2)*4)));
   else
     % homography for base image is just the identity matrix
     % this lets us treat it in the same way we treat all the
     % other images in the rest of the code.
     Hi{i} = eye(3); 
   end
end

%compute where corners of each warped image end up
minx = 1;
miny = 1;
maxx = w(1);
maxy = h(1);
for i = 1:nimages
  %original corner coordinates based on h,w for each image
  cx = [1; 1; w(i); w(i)];
  cy = [1; h(i); 1; h(i)];
 
  % now apply the homography to get the warped corner points
  [cx_warped{i},cy_warped{i}] = applyHomography(Hi{i},cx,cy);
  
  %finding min/max
  if (min(cx_warped{i}) < minx)
      minx = min(cx_warped{i});
  end
  if (max(cx_warped{i}) > maxx)
      maxx = max(cx_warped{i});
  end
  if (min(cy_warped{i}) < miny)
      miny = min(cy_warped{i});
  end
  if (max(cy_warped{i}) > maxy)
      maxy = max(cy_warped{i});
  end

end

% find a bounding rectangle that contains all the warped image
%  corner points (e.g., using mins and maxes of the cx/cy_warped)
% NOTE: I suggest rounding these coordinates to integral values

% upper left corner of bounding rectangle
ul_x = minx;
ul_y = miny;
% lower right corner of bounding rectangle
lr_x = maxx;
lr_y = maxy;

% dimensions of our output image
out_width = (lr_x - ul_x);
out_height = (lr_y - ul_y);

%generate a grid of pixel coordinates that range over the 
% bounding rectangle
[xx,yy] = meshgrid(minx:maxx, miny:maxy);
% NOTE: at this point you may wish to verify a few things:

% 1. the arrays xx and yy should have size [out_height, out_width]
% 2. the values in the array xx should range from ul_x to lr_x
% 3. the values in the array yy should range from ul_y to lr_y

% Use H and interp2 to compute colors in the warped image
for i = 1:nimages
   % warp the pixel grid
   [gridX{i},gridY{i}] = applyHomography(inv(Hi{i}), round(xx(:)), round(yy(:)));
   
   % interpolate colors from the source image onto the new grid
   R = interp2(ims{i}(:,:,1),gridX{i},gridY{i});
   R = reshape(R,size(xx));
   G = interp2(ims{i}(:,:,2),gridX{i},gridY{i});
   G = reshape(G,size(xx));
   B = interp2(ims{i}(:,:,3),gridX{i},gridY{i});
   B = reshape(B,size(xx));
   J{i} = cat(3,R,G,B);
  
   %interp2 puts NaNs outside the support of the warped image
   % let's set them to 0 so that they appear as black in 
   % our result
   J{i}(isnan(J{i})) = 0;

   % also create a binary image that tells us which pixels
   % are valid (that lie inside the warped image)
   mask{i} = ~isnan(R);  

end

imwrite(J{1},'1.jpg', 'jpeg')
imwrite(J{2},'2.jpg', 'jpeg')
imwrite(J{3},'3.jpg', 'jpeg')

for i = 1:nimages
   % blur and clip mask{i} to get an alpha map for each image
   alpha{i} = imfilter(double(mask{i}),fspecial('gaussian',size(mask{baseim}),70));
end

% scale alpha maps to sum to 1 at every pixel location
mask_sum = zeros(size(alpha{baseim}));
for i = 1:nimages
    mask_sum = mask_sum + alpha{i}; 
end
for i = 1:nimages
    alpha{i} = abs(alpha{i}./mask_sum);
end

for i = 1:nimages
   clipped{i} = alpha{i}.*double(mask{i});
   offset{i} = (clipped{i}-min(clipped{i}(clipped{i}>0)));
   offset{i} = offset{i}.*double(mask{i});
end

% finally blend together the resulting images into the final mosaic
K = zeros(size(J{baseim}));
for i = 1:nimages
    K = K + offset{i}.*J{i};
    K = K * 1.1;
end

% display the result
figure(1); 
imagesc(K); axis image;

% save the result to include in your writeup
imwrite(K,'mosaic.jpg', 'jpeg')


