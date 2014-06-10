;;; 1.3 sum of two biggest num
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

;;; 1.9 plus
(defun my-plus (a b)
  (if (= a 0)
      b
      (my-plus (1- a) (1+ b))))

(defun my-plus2 (a b)
  (if (= a 0)
      b
      (1+ (my-plus2 (1- a) b))))

;;; 1.11 f(n) = f(n-1)+2f(n-2)+3f(n-3)
                                        ; iter
(defun f-itera (a b c i n)
  (if (= i n)
      c
      (f-itera (+ a (* 2 b) (* 3 c)) ; new a
               a ; new b
               b ; new c 
               (+ 1 i) ; new i
               n)))

;;; 1.12 pascal
(defun my-pascal-itera (row col)
  (if (> col row)
      (format t "Not valid argument!")
      (if (or (= row col) (= col 0))
          1
          (+ (my-pascal-itera (- row 1) (- col 1))
             (my-pascal-itera (- row 1) col)))))

;;; power   x^n
(defun my-expt-recursion (base power)
  (if (= power 0)
      1
      (* base (my-expt-recursion base (- power 1)))))

(defun my-expt-itera (base power product)
  (if (= power 0)
      product
      (my-expt-itera base
                     (- power 1)
                     (* base product))))

(defun my-even? (n)
  (= (rem n 2) 0))

(defun my-fast-expt (base power)
  (if (= power 0)
      1
      (if (my-even? power)
          (* (my-fast-expt base (/ power 2))
             (my-fast-expt base (/ power 2)))
          (* base (my-fast-expt base (- power 1))))))

;;; greatest common division
(defun my-gcd (a b)
  (if (or (= a 0) (= b 0))
      (format t "Invalid parameter!")
      (if (= b 0)
          a
          (gcd b (rem a b)))))

;;; lambda
((lambda (x) (+ x 3) 3))
