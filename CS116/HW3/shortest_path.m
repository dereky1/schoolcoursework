function [path] = shortest_path(costs)

% given a 2D array of costs, compute the minimum cost vertical path
% from top to bottom which, at each step, either goes straight or
% one pixel to the left or right.
%
% costs:  a HxW array of costs
%
% path: a Hx1 vector containing the indices (values in 1...W) for 
%       each step along the path


[H,W] = size(costs);
k = 1;
M = zeros(H, W);
M(1,:) = costs(1,:);

for i = 2:H
    for j = 1:W
        if(j ~= 1 && j ~= W)
            M(i,j) = costs(i,j) + min([M(i-1,j-1), M(i-1,j), M(i-1,j+1)]);
        elseif(j == 1)
            M(i,j) = costs(i,j) + min([M(i-1,j), M(i-1,j+1)]);
        elseif(j == W)
            M(i,j) = costs(i,j) + min([M(i-1,j-1), M(i-1,j)]);
        end
    end
end

path = [];

for i = H:-1:1
    if(length(path)==0)
        start = min(M(i,:));
    elseif(path(end) == 1)
        start = min(M(i,path(end):path(end)+1));
    elseif(path(end) == W)
        start = min(M(i,path(end)-1:path(end)));
    else
        start = min(M(i,path(end)-1:path(end)+1));
    end
    for j = 1:W
        if(M(i,j) == start)
            path = [path;j];
            break
        end
    end
end

path = flipud(path);