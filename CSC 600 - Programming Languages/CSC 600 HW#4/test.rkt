#lang racket
(provide (all-defined-out))
(define reciprocal
  (lambda (n)
    (if (= n 0)
      "oops!"
      (/ 1 n))))