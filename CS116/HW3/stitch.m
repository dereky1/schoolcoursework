function [result] = stitch(leftI,rightI,overlap);

%stitch(rgb2gray(im2double(imread('one.jpg'))),rgb2gray(im2double(imread('two.jpg'))),5)
% stitch together two grayscale images with a specified overlap
%
% leftI : the left image of size (H x W1)  
% rightI : the right image of size (H x W2)
% overlap : the width of the overlapping region.
%
% result : an image of size H x (W1+W2-overlap)

if (size(leftI,1)~=size(rightI,1)); % make sure the images have compatible heights
  error('left and right image heights are not compatible');
end

% leftI = rgb2gray(leftI);
% rightI = rgb2gray(rightI);
[H,W1] = size(leftI);
[H2,W2] = size(rightI);

avg = abs((leftI(:,W1-overlap:W1-1) - rightI(:,1:overlap)));
short = shortest_path(avg);

for o = 1:H
   for i = 1:overlap
        for j = 1:short(o)
            avg(o,j) = leftI(o,j+W1-overlap-1); 
        end
        for k = short(o)+1:overlap
            avg(o,k) = rightI(o,k);
        end
   end
end

result = [leftI(:,1:W1-overlap),avg,rightI(:,overlap:W2)];
% ima = cat(3,result,result,result);
% imagesc(ima)
