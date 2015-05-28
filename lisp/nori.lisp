(defun incluir (list new)
    (cond (
        (atom (list) (cons new list))
            ((verificanome new list)
                (cond ((verificanum new list) 'contato-existente)
                    ((equal (car new) (caar list)
                        (cons (car list) (cdar list))))
                    ('t (incluir (cdr list) new ))
                    )
                )
            ('t (car list new))
        )
    )
)

;busca
(defun telefone (list look)
    (cond ((atom list)'inexistente)
        ((equal (car look) (caar list)) (cadr list))
        ('t (telefone (cdr list) look))
    )
)

;verifico se o nome já está na lista
(defun verificanome (a l)
    (cond ((atom l) 'nil)
        ((equal (car a) (caar l)) 't)
        ('t (verificanome a (cdr l)))
    )
)

;nome já está na lista: verifico se já tem esse número
(defun verificanum (a l)
    (cond ((atom l) 'nil)
        ((equal (cdar a) (cadr l)) 't)
        ('t (verificanum a (cdr l)))
    )
)
