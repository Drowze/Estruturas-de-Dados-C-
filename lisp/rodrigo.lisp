;Ex1 Fazer função que verifica se um dado átomo ocorre numa lista de átomos fornecida

(defun OcorreAtEmLstAt (A L)
    (cond ((atom L) 'nil) ;verifica se L eh um atomo
          ((equal (CAR L) A) 'T) ;verifica se A eh o primeiro elemento da lista
          ('T (OcorreAtEmLstAt A (CDR L))) ;recursao com o resto da lista
    )
)

;Ex2 Fazer função que remove um dado átomo de uma lista de átomos fornecida (pode haver átomos repetidos)

(defun RemoveAtEndLstAt (A L)
    (cond ((atom L) L) ;se L for atomo retorna L
          ((equal A (car L)) (RemoveAtEndLstAt A (cdr L))); se o primeiro elemento da lista é igual a A
          ('T (cons (car L) (RemoveAtEndLstAt A (cdr L)))); construi lista nova
    )
)

;Ex3 Fazer função que retorna a (soma, sub, mult, div, resto, mõdulo) de dois inteiros dados
;função auxiliar
(defun negativo (x)
    (cond ((equal x 0) 'nil) ;se X for zero retorna nil
          ('t (negAux x x)) ;senao ele nega
    )
)

(defun negAux (A D)
    (cond ((equal A 0) 't) ;se A for zero ele retorna true
          ((equal D 0) 'nil) ;se D for zero ele retorna nil
          ('t (negAux (1+ A) (1- D))) ;se chegar aqui, soma 1 em A e subtrai 1 em D
    )
)


; função para verificar se duas listas DE ATOMOS sao iguais

(defun LstAtmIguais (x y)
    (cond ((atom x) ;quando X eh atomo
              (cond ((atom y) 't) ;se Y atomo retorna true
                    ('t 'nil) ;senao retorna false
              )
          )
          ((atom y) 'nil) ;deixa de ser listas entao retorna false
          ((equal (car x) (car y)) (LstAtmIguais (cdr x) (cdr y))) ;se os dois primeiros sao iguais verifica se o resto eh listas iguais
          ('t 'nil); se chegar aqui retorna nil
    )
)

; função para verificar se duas expressoes simbolicas sao iguais

(defun ExpSmbIguais (x y)
    (cond ((atom x) ;quando X eh atomo
              (cond ((atom y) (equal x y)) ;quando y é atomo verifica se iguais
                    ('t 'nil) ;chegando aqui retorna nil
              )
          )
          ((atom y) 'nil) ;verifica se Y é atomo se sim retorna nil
          ((ExpSmbIguais (car x) (car y)) (ExpSmbIguais (cdr x) (cdr y))) ;se os primeiros forem iguais ele testa se o resto sao iguais
          ('t 'nil) ;se chegar aqui retorna nil
    )
)

; função para verificar se duas listas QUAISQUER sao iguais

(defun ListasIguais (x y)
    (cond 
        ((atom x) ;quando x eh atomo
            (cond 
                ((atom y) 't) ;se Y eh atomo retorna true
                ('t 'nil) ;senao retorna false
            )
         
          ((atom y) 'nil) ;se Y atomo retorna NIL
          ((ExpSmbIguais (car x) (car y)) (ListasIguais (cdr x) (cdr y))); se forem iguais ele vai verificar a lista
          ('t 'nil);se chegar aqui retorna nil
         )
    )
)

;verificar se é maior
(defun GT (x y)
    (cond 
        ((equal x 0) ;quando x for 0
            (cond
                ((negativo y) x) ; Se Y for negativo retorna X
                ('t y) ;Se Y positivo retorna Y
            )
        )
        ((equal y 0);quando y for 0
            (cond
                ((negativo x) y) ; Se X for negativo retorna Y
                ('t x) ;Se X positivo retorna X
            )
        )
        ((negativo x)
            (cond 
                ((negativo y) (1- (GT (1+ x)(1+ y)))) ;quando X e Y é negativo, chama a recursao para ver qual o maior.
                ('t y) ;quando X é negativo e Y é positivo, retorna Y, pois Y eh o maior.
            )
        )
        ((negativo y) x);quando y é negativo retona x, pois X eh o maior.
        ('t (1+ (GT (1- x)(1- y))));caso os X e Y positivo, chama recursão
    )
)

;Exercicios Propostos
;1- Escreva um predicado que verifica se um numero inteiro é negativo
;feito na linha 21, a funçao negativo

;2- Escreva as funções soma e subt que realizam, respectivamente, as operações aritméticas de adição e de subtração. 
;   Considere que o domínio de anbas as funções é o conjunto dos pares ordenados de números inteiros,
;   e que o contradomínio de ambas é o conjunto dos números inteiros.

(defun soma (X Y)
    (cond
        ((negativo Y)
            (cond
                 ((negativo X) (soma (1+ X) (1- Y)))
                 ('t (soma Y X))
            )
        )
        ((equal y 0) x)
        ('t (soma (1+ X) (1- Y)))
    )
)

(defun subtracao (X Y)
    (cond
        ((equal y 0) x)
        ((negativo Y) (subtracao (1+ X) (1+ Y)))
        ('t (subtracao (1- X) (1- Y)))
    )
)

;3- Escreva os predicados NE, GT, GE, LT, LE (respectivamente, diferente, maior, maior ou 
;   igual, menor, e menor ou igual). Considere que o domínio de todos os predicados é o 
;   conjunto dos números inteiros.

(defun diferentes (X Y)
    (cond
        ((equal X Y) 'nil)
        ('t 't)
    )
)

(defun maior (X Y)
    (cond 
        ((equal x 0) ;quando x for 0
            (cond
                ((negativo y) x) ; Se Y for negativo retorna x
                ('t y) ;Se Y positivo retorna Y
            )
        )
        ((equal y 0);quando y for 0
            (cond
                ((negativo x) y) ; Se X for negativo retorna Y
                ('t x) ;Se X positivo retorna X
            )
        )
        ((negativo x)
            (cond 
                ((negativo y) (1- (maior (1+ x)(1+ y)))) ;quando X e Y é negativo, chama a recursao para ver qual o maior.
                ('t y) ;quando X é negativo e Y é positivo, retorna Y, pois Y eh o maior.
            )
        )
        ((negativo y) x);quando y é negativo retona x, pois X eh o maior.
        ('t (1+ (maior (1- x)(1- y))));caso os X e Y positivo, chama recursão
    )

)

(defun maiorigual (X Y)
    (cond
        ((equal X Y) 't)
        ('t (maior X Y))
    )
)

(defun menor (X Y)
    (cond 
        ((equal x 0) ;quando x for 0
            (cond
                ((negativo y) y) ; Se Y for negativo retorna y
                ('t x) ;Se Y positivo retorna X
            )
        )
        ((equal y 0);quando y for 0
            (cond
                ((negativo x) x) ; Se X for negativo retorna X
                ('t y) ;Se X negativo retorna Y
            )
        )
        ((negativo x)
            (cond 
                ((negativo y) (1- (menor (1+ x)(1+ y)))) ;quando X e Y é negativo, chama a recursao para ver qual o menor.
                ('t x) ;quando X é negativo e Y é positivo, retorna Y, pois Y eh o maior.
            )
        )
        ((negativo y) y);quando y é negativo retona y, pois X eh o maior.
        ('t (1+ (menor (1- x)(1- y))));caso os X e Y positivo, chama recursão para ver qual o menor.
    )

)

(defun menorigual (X Y)
    (cond
        ((equal X Y) 't)
        ('t (menor X Y))
    )
)

;4- Escreva a função abs que calcula valor absoluto ou em módulo. Considere que o domínio 
;   dessa função é o conjunto dos números inteiros, e que o contradomínio dela é o conjunto 
;   dos números naturais.

(defun modulo (X)
    (cond
        ((negativo X) (subtracao 0 x))
        ('t X)
    )
)

;5- Escreva as funções mult, divi e rest que realizam, respectivamente, as operações
;   aritméticas de multiplicação, divisão inteira e resto da divisão inteira. Considere que o 
;   domínio de todas as funções é o conjunto dos pares ordenados de números inteiros, e que 
;   o contradomínio de todas elas é o conjunto dos números inteiros.

(defun mult (X Y)
    (cond
        ((equal Y 0) 0)
        ((equal X 1) Y)
        ((negativo Y) (SUBTRACAO(mult X (1+ Y)) X))
        ('t (soma X (mult X (1- Y))))
    )
)

(defun divi (X Y)
    (cond
        
    
    )
)