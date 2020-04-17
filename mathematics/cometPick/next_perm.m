function [res, suc] = next_perm(S)

fin = true;
rev = 0;
for i = flip(1:(size(S, 2)-1))
    if S(i) <  S(i+1)
        fin = false;
        rev = i;
        break;
    end
end

if fin
   res = S;
   suc = false;
   return
end

head = 0;
for i = flip(1:(size(S, 2)))
    if S(rev) < S(i)
        head = i;
        break;
    end
end


[S(head), S(rev)] = deal(S(rev), S(head));
S(rev+1:end) = flip(S(rev+1:end));


res = S;
suc = true;

end

