
%derek yang
%63118832

set = input('Which Set?');
if set == 1
    filelist = dir('C:\Users\Derek\Desktop\CS116\HW1\set1\*.jpg');
    A = zeros(215,300);
elseif set == 2
    filelist = dir('C:\Users\Derek\Desktop\CS116\HW1\set2\*.jpg');
    A = zeros(164,398);
end

c = 1;
for i=1:length(filelist)
       if set == 1
           imname = ['C:\Users\Derek\Desktop\CS116\HW1\set1\' filelist(i).name];
       elseif set == 2
           imname = ['C:\Users\Derek\Desktop\CS116\HW1\set2\' filelist(i).name];
       end
       nextim = im2double(imread(imname));
       A = (A + nextim);
       c = c + 1;
end

A = A/c;
imshow(A)