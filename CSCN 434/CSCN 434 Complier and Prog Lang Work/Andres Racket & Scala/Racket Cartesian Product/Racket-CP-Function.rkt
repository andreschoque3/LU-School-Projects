#lang racket
(define (my-cp lista listb listc)
  (map (lambda (x) (map (lambda (y) (map (lambda (z) (list x y z) ) listc) ) listb) ) lista)) 