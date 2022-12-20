#lang racket
(define (my-cp-scaled lista listb listc num1 num2 num3)
  (map (lambda (x) (* num1 x) (map (lambda (y) (* num2 y) (map (lambda (z) (* num3 z) (list (* num1 x) (* num2 y) (* num3 z) ) ) listc) ) listb) ) lista))