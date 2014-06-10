(defun square (x)
  (* x x))

(defun good-enough (guess x)
  (< (abs (- (square guess) x)) 0.0001))

(defun improve (guess x)
  (/ (+ guess (/ x guess)) 2))

(defun sqrt-itera (guess x)
  (if (good-enough guess x)
      guess
      (sqrt-itera (improve guess x) x)))
