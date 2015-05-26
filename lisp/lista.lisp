; 1) 
(defun negativo (X)
    (cond ((equal X 0)'nil)
        ('t(neg X X))
    )
)

(defun neg  (X Y)
    (cond ((equal X 0)'t)
        ((equal Y 0)'nil)
        ('t(neg(1+ X)(1- Y)))
    )
)

; 2) 
(defun soma (X Y)
    (cond
        ((negativo Y)
            (cond
                 ((negativo X) (soma (1+ X) (1- Y)))
                 ('t (soma Y X))
            )
        )
        ((equal Y 0) X)
        ('t (soma (1+ X) (1- Y)))
    )
)

(defun subt (X Y)
    (cond
        ((equal Y 0) X)
        ((negativo Y) (subt (1+ X) (1+ Y)))
        ('t (subt (1- X) (1- Y)))
    )
)

; 3)
(defun NE (X Y)
    (cond 
        ((equal X Y) 'nil)
        ('t 't)
    )
)

(defun GT (X Y)
    (cond 
        ((equal X 0)
            (cond
                ((negativo Y) X)
                ('t Y)
            )
        )
        ((equal Y 0)
            (cond
                ((negativo X) Y)
                ('t X)
            )
        )
        ((negativo X)
            (cond 
                ((negativo Y) (1- (GT (1+ X)(1+ Y))))
                ('t Y)
            )
        )
        ((negativo Y) X)
        ('t (1+ (GT (1- X)(1- Y))))
    )
)

(defun GE (X Y)
    (cond
        ((equal X Y) 't)
        ('t (GT X Y))
    )
)

(defun LT (X Y)
    (cond 
        ((equal X 0)
            (cond
                ((negativo Y) Y)
                ('t X)
            )
        )
        ((equal Y 0)
            (cond
                ((negativo X) X)
                ('t Y)
            )
        )
        ((negativo X)
            (cond 
                ((negativo Y) (1- (LT (1+ X)(1+ Y))))
                ('t X)
            )
        )
        ((negativo Y) Y)
        ('t (1+ (LT (1- X)(1- Y))))
    )
)

(defun LE (X Y)
    (cond
        ((equal X Y) 't)
        ('t (LT X Y))
    )
)

; 4)
(defun modu (X)
    (cond
        ((negativo X) (subt 0 X))
        ('t X)
    )
)

; 5)
(defun mult (X Y)
    (cond
        ((equal Y 0) 0)
        ((equal X 1) Y)
        ((negativo Y) (subt(mult X (1+ Y)) X))
        ('t (soma X (mult X (1- Y))))
    )
)

(defun divi (X Y)
    (cond
        ((equal Y 0) 'nil)
        ((equal (LT X Y) X) 0)
        ((equal X Y) 1)
        ('t divi (1+ (divi (subt X Y) Y)))
    )
)