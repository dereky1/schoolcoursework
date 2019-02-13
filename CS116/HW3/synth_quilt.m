function output = synth_quilt(tindex,tile_vec,tilesize,overlap)
%
% synthesize an output image given a set of tile indices
% where the tiles overlap, stitch the images together
% by finding an optimal seam between them
%
%  tindex : array containing the tile indices to use
%  tile_vec : array containing the brightness values for each tile in vectorized format
%             this will be a 2D array of dimensions  (tilesize^2) x numtiles so that 
%             each column contains the values for a given tile (see sampletiles.m)
%
%  tilesize : the size of the tiles  (should be sqrt of the size of the tile vectors)
%  overlap : overlap amount between tiles
%
%  output : the output image

if (tilesize ~= sqrt(size(tile_vec,1)))
  error('tilesize does not match the size of vectors in tile_vec');
end

% each tile contributes this much to the final output image width 
% except for the last tile in a row/column which isn't overlapped 
% by additional tiles
tilewidth = tilesize-overlap;  

% compute size of output image based on the size of the tile map
outputsize = size(tindex)*tilewidth+overlap;

% 
% stitch each row into a separate image by repeatedly calling your stitch function
% 
width = size(tindex);

for j = 1:width(1)
    stitchRows{j} = [];
    for i = 1:width(2)-1
        imageL = reshape(tile_vec(:,tindex(j,i)),[tilesize,tilesize]);
        imageR = reshape(tile_vec(:,tindex(j,i+1)),[tilesize,tilesize]);
        if(size(stitchRows{j}) ~= 0)
            stitchRows{j} = stitch(stitchRows{j},imageR,overlap);
        else
            stitchRows{j} = [stitchRows{j},stitch(imageL,imageR,overlap)];
        end
    end
end

%
% now stitch the rows together into the final result 
% (I suggest calling your stitch function on transposed row 
% images and then transpose the result back)
%
output = [];
for i = 1:width(1)-1
    imgL = stitchRows{i}.';
    imgR = stitchRows{i+1}.';
    if(size(output) ~= 0)
        output = stitch(output,imgR,overlap);
    else
        output = [output,stitch(imgL,imgR,overlap)];
    end
end
output = output.';
ima = cat(3,output,output,output);
imwrite(ima,'hw3.jpg','jpeg')

