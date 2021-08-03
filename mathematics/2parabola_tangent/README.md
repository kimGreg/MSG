# 2개의 포물선의 공통 접선

## 문제

y = x^2 + k 와 x = y^2 + k 두 포물선의 공통접선이 3개가 나올 k의 범위를 구하시오

## 시각화
![](/mathematics/2parabola_tangent/tangent.gif)

## 코드
```matlab
clear all, clc
syms x y k m t

K = -2:1/8:1

for k_idx = 1:size(K, 2)
    k = K(k_idx);
    eqn1 = y == x^2 + k;
    eqn2 = x == y^2 + k;

    fimplicit(eqn1, 'LineWidth', 1, 'color', 'k')
    hold on
    grid on
    xlabel('x');
    ylabel('y');
    title(sprintf("k : %0.5f", k));
    fimplicit(eqn2, 'LineWidth', 1, 'color', 'k')


    Deqn1 = t == k - ((m^2)/4);
    Deqn2 = t == (1/(4*m)) - m*k;

    ans = solve(Deqn1, Deqn2);

    for i = ans
        eqn3 = y == i.m*x + i.t;
        fimplicit(eqn3)
    end
    saveas(gcf, sprintf("tangent%d.png", k_idx))
    hold off
end
```
