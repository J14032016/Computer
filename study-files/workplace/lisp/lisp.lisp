;;; getting in
(defun simply-plus (x y)
  "This is a simply plus function."
  (format t "~d plus ~d is ~d" x y (+ x y)))

(defun foo (x)
  (format t "Parameter : ~a~%" x))


;;; read in
(defun simply-readin ()
  "read in a number to process"
  (let ((var (read)))
    (if (> var 0)
        (format t "~d is bigger than 0" var)
        (format t "~d is smaller than 0" var))))

;; concat function
(defun ccc ()
  (let ((fm "world")
        (com  "hello "))
    (format t "Print ~a" (concatenate 'string com fm))))

;;; lambda function
(defparameter *fn* (let ((count 0)) #'(lambda () (setf count (+ 1 count)))))

;;; constant value
(defvar *x* 10)
(defun foo () (format t "X is : ~d~%" *x*))

;;; dotimes
(dotimes (x 9)
  (dotimes (y 9)
    (format t "~3d" (* (+ 1 x) (+ 1 y))))
  (format t "~%"))

(defun sum (n)
  (let ((s 0))
    (dotimes (i n s)
      (incf s i))))

;;; input and output
(defun askme (string)
  (format t "~a~%" string)
  (format t "enter your age:")
  (read)
  (format t "you age is"))


(defun my-ask ()
  (format t "input a number : ")
  (let ((var (read)))
    (if (numberp var)
        var
        (my-ask))))

;;; defmacro
(defmacro triple (x)
  `(+ ,x ,x ,x))


;;; Function invoking
(defun diff-s (l)
  "calculate different s"
  (if (string= l "circule")
      (S-circule 3)
      (S-rectangle 3)))
(defun S-circule (x)
  (format t "The s of circule is : ~a"
          (* pi (expt x 2))))
(defun S-rectangle (x)
  (format t "The s of rectangle is : ~a"
          (expt x 2)))

(defun switch (a)
  "Switch the two elements of the list"
  (list2 (second a) (first a)))
(defun list2 (o1 o2)
  "return the list of its two arguments in order"
  (cons o1 (cons o2'())))


;;; if cond
(defun my-absval (x)
  "return the absolute value of the argument"
  (if (< x 0)
      (- x)
      x))

(defun my-absval2 (x)
  "return the absolute value of the argument using cond"
  (cond ((< x 0) (- x))
        ((> x 0) x)
        ((= x 0) 0)))

(defun my-division (x y)
  "return x/y if y is not equal to zero,else return 9999"
  (if (= y 0)
      9999
      (/ x y)))



;;; recursion
(defun my-recursion-sum (x y)
  "this is a simple sum function implemented by recursion"
  (if (zerop x) y
      (my-recursion-sum (1- x) (1+ y))))

(defun my-factorial (x)
  "this is a function to calculate factorial"
  (if (= x 0) 1 (* x (my-factorial (1- x)))))

(defun my-arrange (base power)
  "this is a function to calculate arrage"
  (if (> power base)
      (format t "The power cannot be bigger than the base!")
      (/ (my-factorial base) (my-factorial (- base power)))))

(defun my-combination (base power)
  "this is a function to calculate arrage"
  (if (> power base)
      (format t "The power cannot be bigger than the base!")
      (/ (my-factorial base) (my-factorial power) (my-factorial (- base power)))))



;;; useful function
(defun arrangement-function ()
  " use sort-function to sort the list "
  (format t "The sequence of the list you just type in is ~a"
          (sort (read) #'<)))


(defun testcon ()
  (concatenate 'string "gcc -g -Wall -o "
	       "hello "
	       "hello.c"))

;;; area of the circle
(defun area-circle (radius)
  (if (> radius 0)
      (progn
        (format t "The area of the circle is : ")
        (* radius radius PI))
      (format t "The radius of a circle must be positive!")))
        

;;; fibonacci
(defun my-fibonacci (a)
  (do ((n 0 (1+ n))
       (cur 1 next)
       (next 1 (+ cur next)))
      ((= a n))
    (format t "~d  " cur)))


;;; loop
(defun sum-to-100 (a)
  (let ((sum 0))
    (do ((n 0 (1+ n)))
        ((= a n))
      (incf sum n))
    (format t "~d" sum)))


;;; car cdr con
(defun my-third (a)
  (car (cdr (cdr a))))

;;; list length

;;; sum of two biggest num
(defun sum-of-two-big (a b c)
  (if (>= a b)
      (if (>= b c)
          (+ a b)
          (if (>= a c)
              (+ a c)
              (+ c a)))
      (if (>= a c)
          (+ b a)
          (if (>= b c)
              (+ b c)
              (+ c b)))))

;;; truncate
(defun my-truncate (x)
  (if (> x 0)
      (floor x)
      (ceiling x)))

