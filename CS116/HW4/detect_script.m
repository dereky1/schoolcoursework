%
% This is a simple test script to exercise the detection code.
%
% It assumes that the template is exactly 16x16 blocks = 128x128 pixels.  
% You will want to modify it so that the template size in blocks is a
% variable you can specify in order to run on your own test examples
% where you will likely want to use a different sized template
%

% load a training example image
Itrain = im2double(rgb2gray(imresize(imread('test/panda3.jpg'),1.50)));

%have the user click on some training examples.  
% If there is more than 1 example in the training image (e.g. faces), you could set nclicks higher here and average together
nclick = 5;
nclick2 = 6;
templ_size = 16;
block = round(templ_size/2);
figure(1); clf;
imshow(Itrain);
[x,y] = ginput(nclick); %get nclicks from the user

%compute 8x8 block in which the user clicked
blockx = round(x/block);
blocky = round(y/block); 

%visualize image patch that the user clicked on
% the patch shown will be the size of our template
% since the template will be 16x16 blocks and each
% block is 8 pixels, visualize a 128pixel square 
% around the click location.
figure(2); clf;
for i = 1:nclick
  patch = Itrain(block*blocky(i)+(-(block^2-1):block^2),block*blockx(i)+(-(block^2-1):block^2));
  figure(2); subplot(3,2,i); imshow(patch);
end

% compute the hog features
f = hog(Itrain); %hog of got7
figure(10)
imshow(hogdraw(f,15));
% compute the average template for the user clicks
postemplate = zeros(templ_size,templ_size,9);
for i = 1:nclick
  postemplate = postemplate + f(blocky(i)+(-(block-1):block),blockx(i)+(-(block-1):block),:); 
end
postemplate = postemplate/nclick;

% TODO: also have the user click on some negative training
% examples.  (or alternately you can grab random locations
% from an image that doesn't contain any instances of the
% object you are trying to detect).
figure(4); clf;
imshow(Itrain);
[x2,y2] = ginput(nclick2); %get nclicks from the user

blockx2 = round(x2/block);
blocky2 = round(y2/block); 

figure(5); clf;
for i = 1:nclick2
  patch2 = Itrain(block*blocky2(i)+(-(block^2-1):(block^2)),block*blockx2(i)+(-(block^2-1):(block^2)));
  figure(5); subplot(4,3,i); imshow(patch2);
end

% now compute the average template for the negative examples
negtemplate = zeros(templ_size,templ_size,9);
for i = 1:nclick2
  negtemplate = negtemplate + f(blocky2(i) + (-(block-1):block),blockx2(i) + (-(block-1):block),:); 
end
negtemplate = negtemplate/nclick2;

% our final classifier is the difference between the positive
% and negative averages
template = postemplate - negtemplate;

%
% load a test image
%
Itest= im2double(rgb2gray(imread('test/panda2.jpg')));
figure(8);
hi = hog(Itest);
imshow(hogdraw(hi));

% find top 8 detections in Itest
ndet = 8;
[x,y,score] = detect(Itest,template,ndet);
ndet = length(x);

%display top ndet detections
figure(3); clf; imshow(Itest);
for i = 1:ndet
  % draw a rectangle.  use color to encode confidence of detection
  %  top scoring are green, fading to red
  hold on; 
  h = rectangle('Position',[x(i)-(block^2) y(i)-(block^2) (templ_size*block) (templ_size*block)],'EdgeColor',[(i/ndet) ((ndet-i)/ndet)  0],'LineWidth',3,'Curvature',[0.3 0.3]); 
  hold off;
end
