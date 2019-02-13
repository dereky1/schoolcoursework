  %
  % morphing script
  %

  % load in two images...
  I1 = im2double(imread('dog1.jpg'));
  I2 = im2double(imread('dog2.jpg'));

  % get user clicks on keypoints using either ginput or cpselect too
   pts_img1 = [];
   pts_img2 = [];
  %run interactive select tool to click corresponding points on base and non-base image
  [imone, imtwo] = cpselect(I1,I2,'Wait',true);
  pts_img1 = [pts_img1 imone'];
  pts_img2 = [pts_img2 imtwo'];

  % the more pairs of corresponding points the better... ideally for 
  % faces ~20 point pairs is good include several points around the
  % outside contour of the head and hair.
 
  % you may want to save pts_img1 and pts_img2 out to a .mat file at
  % this point so you can easily reload it without having to click
  % again. 
  
  %save('morph_var.mat', 'pts_img1', 'pts_img2')
  %load('morph_var.mat', 'pts_img1', 'pts_img2');
  
  % append the corners of the image to your list of points
  % this assumes both images are the same size and that your
  % points are in a 2xN array
  [h,w,~] = size(I1);
  pts_img1 = [pts_img1 [0 0]' [w 0]' [0 h]' [w h]'];
  pts_img2 = [pts_img2 [0 0]' [w 0]' [0 h]' [w h]'];

  % generate triangulation 
  pts_halfway = 0.5*pts_img1 + 0.5*pts_img2;
  tri = delaunay(pts_halfway(1,:),pts_halfway(2,:));
  
  % now produce the frames of the morph sequence
  for fnum = 1:6
    t = (fnum-1)/5;

    % intermediate key-point locations
    pts_target = (1-t)*pts_img1 + t*pts_img2;                

    %warp both images towards target shape
    I1_warp = warp(I1,pts_img1,pts_target,tri);              
    I2_warp = warp(I2,pts_img2,pts_target,tri);      
    
%     figure(1); clf;
%     
%   subplot(2,2,1);
%   imagesc(I1); axis image; hold on;
%   triplot(tri,pts_img1(1,:),pts_img1(2,:),'r','linewidth',1);
% 
%   subplot(2,2,2);
%   imagesc(I1_warp); axis image; hold on;
%   triplot(tri,pts_target(1,:),pts_target(2,:),'r','linewidth',1);
%   
%   subplot(2,2,3);
%   imagesc(I2); axis image; hold on;
%   triplot(tri,pts_img2(1,:),pts_img2(2,:),'r','linewidth',1);
% 
%   subplot(2,2,4);
%   imagesc(I2_warp); axis image; hold on;
%   triplot(tri,pts_target(1,:),pts_target(2,:),'r','linewidth',1);
%   axis image; drawnow;
%   pause;

    % blend the two warped images
    Iresult = (1-t)*I1_warp + t*I2_warp;                     

    % display frames
    figure(3); clf; imagesc(Iresult); axis image; drawnow;   

    % alternately save them to a file to put in your writeup
    imwrite(Iresult,sprintf('frame_%2.2d.jpg',fnum),'jpg');   
  end
