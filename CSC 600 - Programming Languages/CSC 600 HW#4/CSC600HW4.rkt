#lang racket
(define (sum list)
  (+ (car list) ; get head of list
     (sum (cdr list)))) ; apply sum to the remaining mems of list
(define (square-sum list)
  (+ (* (car list) (car list)) ; multiply the car of vars with itself
     apply square-sum (cdr list)))
(define (mean list) 
  (/ (sum list) (length list))) ; perform sum and divide by by the number of elements
(define (meanofsquare list)
  (/ (square-sum list) (length list))) ; repeat the above for a list of squares.
(define (sigma list)
  (let* ((meanoflist (mean args)
               (meansquared (* meanoflist meanoflist)
                            (meanofsquare (mean args)))
               (sqrt (- meanofsquare meansquared))))))
(sigma '(1 2 3 4 5 6))