clear all, clc
addpath('../');

arr = [0 0 0 0 0 1 1 1 1]; % 0:odd 1:even
cnt = 0;

while true
    odd = 0;
    even = 0;
    
    for i = arr
       if i == 0
        odd = odd + 1;
       else
        even = even + 1;
       end
       
       if odd == 2 && even < 2
           cnt = cnt+1;
           break
       elseif even == 2 && odd < 2
           break
       end
    end
    
    [arr, suc] = next_perm(arr);
    if ~suc
        break
    end
    
end

Answer = fopen('answer2.txt', 'w');
fprintf(Answer, sprintf("ans : %d", cnt));
