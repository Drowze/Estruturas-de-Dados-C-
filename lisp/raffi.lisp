;car 1 elmt a esquerda 
;cdr 1 elemento mais a direita
;atom 

(defun negativo (x)
    (cond ((equal x 0)'nil)
        ('t(neg x x))
    )
)


(defun neg  (x y)
    (cond ((equal x 0)'t)
        ((equal y 0)'nil)
        ('t(neg(1+ x)(1- y)))
    )
)

(defun soma (x y)
    (cond ((equal y 0)x)      
        ((negativo y)(soma(1- x)(1+ y)))
        ('t(soma(1+ x)(1- y)))
    )
)

(defun sub (x y)
    (cond ((equal y 0) x)
        ((negativo y)(sub(1+ x)(1+ y)))
        ('t(sub(1- x)(1- y)))
    )    
)

;NE = diferente 
;GT = maior 
;GE = maior ou igual
;LT = menor
;LE = menor ou igual

(defun NE (x y)
    (cond ((equal x y) 'nil)
        ('t 't)
    )
)

(defun GT (x y)
    (cond   ((equal x y) 'nil)
        ((negativo x) 
            (cond
                ((equal y 0) 'nil)
                ((equal (negativo y) 't) (GT (1+ x)(1+ y)))
            )
        ) 
        ((negativo y)
            (cond
                ((equal x 0) 't) 
                ((equal (negativo x) 't) (GT (1+ x)(1+ y)))
            )
        )
        ((equal y 0) 't)
        ((equal x 0) 'nil)
        ('t (GT (1- x)(1- y)))
    )
)

(defun GE (x y)
    (cond
        ((equal x y)'t)
        ('t (GT x y))
    )
)

(defun LT (x y)
    (cond ((equal x y) 'nil)
        ((negativo x)
            (cond
                ((equal y 0)'nil)
                ((equal (negativo y)'t)(LT (1+ x)(1+ y)))
                ((equal(negativo y)'nil)'t)
            )
        )

        ((negativo y)
            (cond
                ((equal x 0) 'nil)
                ((equal(negativo x)'t)(LT (1+ x)(1+ y)))
                ((equal(negativo x)'nil)'t)
            )
        )
        
        ((equal x 0)'t)
        ((equal y 0)'nil)
        ('t (LT (1- x)(1- y)))

    )
)

(defun LE (x y)
    (cond ((equal x y)'t)
        ('t (LT x y))
        )
    )
;   4- Escreva a função abs que calcula valor absoluto ou em módulo. Considere que o domínio
;   dessa função é o conjunto dos números inteiros, e que o contradomínio dela é o conjunto
;   dos números naturais.