(defun my-gcd (a b)
  (if (= b 0)
      a
      (my-gcd b (rem a b))))

(defun make-rat (n d)
  (let ((g (my-gcd n d)))
    (cons (/ n g) (/ d g))))
 
(defun numer (x)
  (car x))

(defun denom (x)
  (cdr x))

(defun add-rat (x y)
  (make-rat (+ (* (numer x) (denom y))
               (* (denom x) (numer y)))
            (* (denom x) (denom y))))

(defun sub-rat (x y)
  (make-rat (- (* (numer x) (denom y))
               (* (denom x) (numer y)))
            (* (denom x) (denom y))))

(defun mul-rat (x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))

(defun div-rat (x y)
  (make-rat (/ (numer x) (numer y))
            (/ (denom x) (denom y))))

(defun equ-rat (x y)
  (and (= (numer x) (numer y))
       (= (denom x) (denom y))))

(defvar rat1 (make-rat 1 3))
(defvar rat2 (make-rat 1 6))
