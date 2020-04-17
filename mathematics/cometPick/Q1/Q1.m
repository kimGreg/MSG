clear all, clc
addpath('../');

s = [1 1 2 2 3 4 5];
cnt = 0;

while true
    for i = 1:(size(s, 2)-1)
      if s(i) + s(i+1) == 3
          cnt = cnt+1;
           break;
       end
    end
    [s, suc] = next_perm(s);
    if ~suc
        break 
    end
end

Answer = fopen('answer.txt', 'w');
fprintf(Answer, sprintf("ans : %d", cnt));