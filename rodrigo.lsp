;Função para verificar se duas listas DE ATOMOS sao iguais
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

;Função para verificar se duas expressoes simbolicas sao iguais
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

;Função para verificar se duas listas QUAISQUER sao iguais
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
;----------------------------------------------------------------------------------------------------------------------------
;Exercicios Propostos
;1- Escreva um predicado que verifica se um numero inteiro é negativo
(defun negativo (x)
	(cond ((equal x 0) 'nil) ;se X for zero retorna nil
	      ('t (negAux x x)) ;senao ele chama negAux passando X
	)
)

(defun negAux (A D)
	(cond ((equal A 0) 't) ;se A for zero ele retorna true
		  ((equal D 0) 'nil) ;se D for zero ele retorna nil
		  ('t (negAux (1+ A) (1- D))) ;caso D diferente de 0, recursao aumentando A e diminuindo D
	)
)

;2- Escreva as funções soma e subt que realizam, respectivamente, as operações aritméticas de adição e de subtração. 
;   Considere que o domínio de anbas as funções é o conjunto dos pares ordenados de números inteiros,
;   e que o contradomínio de ambas é o conjunto dos números inteiros.

(defun soma (X Y)
	(cond
		((equal y 0) x) ;se Y for 0 retorna X
		((negativo Y) (soma (1- X) (1+ Y))) ;se y diferente de 0, verifica se Y é negativo, se sim faz recursao diminuindo X e aumentando Y
		('t (soma (1+ X) (1- Y))) ;senao, y é positivo entao, faz recursao aumentando X e diminuindo Y
	)
)

(defun subtracao (X Y)
	(cond
		((equal y 0) x) ;se Y for 0 retorna X
		((negativo Y) (subtracao (1+ X) (1+ Y)));se y diferente de 0, verifica se Y é negativo, se sim faz recursao aumentando X e aumentando Y
		('t (subtracao (1- X) (1- Y))) ;senao, y é positivo entao, faz recursao diminuindo X e diminuindo Y
	)
)

;3- Escreva os predicados NE, GT, GE, LT, LE (respectivamente, diferente, maior, maior ou 
;	igual, menor, e menor ou igual). Considere que o domínio de todos os predicados é o 
;	conjunto dos números inteiros.

(defun diferentes (X Y)
	(cond
		((equal X Y) 'nil) ;se X for igual a Y retorna NIL
		('t 't) ;senao retorna true
	)
)

(defun maior (X Y)
	(cond 
		((equal x 0) ;se X for zero entra na condicao
			(cond
				((negativo y) x) ;se Y for negativo retorna X
				('t y) ;senao retorna Y
			)
		)
		((equal y 0) ;se Y for zero entra na condicao
			(cond
				((negativo x) y) ;se X for negativo retorna Y
				('t x) ;senao retorna X
			)
		)
		((negativo x) ;se X for negativo entra na condicao
			(cond 
				((negativo y) (1- (maior (1+ x)(1+ y)))) ;se Y negativo, faz recursao aumentando X e aumentando Y 
				('t y) ;se Y é positivo e X negativo retorna Y
			)
		)
		((negativo y) x) ;quando y é negativo retona x
		('t (1+ (maior (1- x)(1- y)))) ;caso X e Y positivo, chama recursão diminuindo X e diminuindo Y
	)
)

(defun maiorigual (X Y)
	(cond
		((equal X Y) 't) ;se X e Y forem iguais retorna TRUE
		('t (maior X Y)) ;senao chama funcao maior
	)
)

(defun menor (X Y)
	(cond 
		((equal x 0) ;se X for zero entra na condicao
			(cond
				((negativo y) y) ;se Y for negativo retorna Y
				('t x) ;senao retorna X
			)
		)
		((equal y 0) ;se Y for zero entra na condicao
			(cond
				((negativo x) x) ;se X for negativo retorna X
				('t y) ;senao retorna Y
			)
		)
		((negativo x) ;se X for negativo entra na condicao
			(cond 
				((negativo y) (1- (menor (1+ x)(1+ y)))) ;se Y negativo, faz recursao aumentando X e aumentando Y 
				('t x) ;se Y é positivo e X negativo retorna X
			)
		)
		((negativo y) y);quando y é negativo retona y
		('t (1+ (menor (1- x)(1- y)))) ;caso X e Y positivo, chama recursão diminuindo X e diminuindo Y
	)

)

(defun menorigual (X Y)
	(cond
		((equal X Y) 't) ;se X e Y forem iguais retorna TRUE
		('t (menor X Y)) ;senao chama funcao menor
	)
)

;4- Escreva a função abs que calcula valor absoluto ou em módulo. Considere que o domínio 
;   dessa função é o conjunto dos números inteiros, e que o contradomínio dela é o conjunto 
;   dos números naturais.

(defun modulo (X)
	(cond
		((negativo X) (subtracao 0 x)) ;se X for negativo, faz subtracao com zero, pois inverte o sinal
		('t X) ;senao retorna X
	)
)

;5- Escreva as funções mult, divi e rest que realizam, respectivamente, as operações
;   aritméticas de multiplicação, divisão inteira e resto da divisão inteira. Considere que o 
;   domínio de todas as funções é o conjunto dos pares ordenados de números inteiros, e que 
;   o contradomínio de todas elas é o conjunto dos números inteiros.

(defun mult (X Y)
	(cond
		((equal Y 0) 0) ;se Y igual a zero retorna zero, X * 0 = 0
		((equal X 1) Y) ;se X igual a 1 retorna Y, 1 * Y = Y
		((negativo Y) (SUBTRACAO (mult X (1+ Y)) X)) ;se Y for negativo entra na subtracao pois multiplicacao com negativo tende a diminuir
		('t (soma X (mult X (1- Y)))) ;senao, usa soma mesmo X sendo negativo
	)
)
;6- Escreva uma função que calcula a potenciação. Considere que o domínio dessa função é o 
;   conjunto dos pares ordenados formados por um número inteiro (a base) e um número 
;   natural (o expoente) e que o contradomínio dela é o conjunto dos números inteiros.
(defun poten (X Y)
	(cond
		((equal Y 0) 1) ;compara Y com 0, se igual retorna 1
		;((negativo y) (mult (poten X (1+ Y)) X)) acho que no lugar do mult eh divi
		('t (mult (poten X (1- Y)) X)) ;multiplicacao com a recursao diminuindo o Y(loop)
	)
)


;7- Escreva uma função que calcula e retorna o fatorial de um dado numero natural
(defun fatorial (X)
	(cond
		((equal X 0) 1) ;compara x com 0, se sim retorna 1, pois fatorial de 0 é 1
		;((negativo X) (mult(fatorial (1- X)) X)) acho que no lugar de mult eh divi
		('t (mult(fatorial (1- X)) X)) ;;multiplicacao com a recursao diminuindo o X
	)
)

;9- Escreva um predicado que verifica se um átomo ocorre em uma lista de átomos.
(defun OcorreAtEmLstAt (A L)
	(cond ((atom L) 'nil) ;verifica se L eh um atomo
		  ((equal (CAR L) A) 'T) ;verifica se A eh o primeiro elemento da lista
		  ('T (OcorreAtEmLstAt A (CDR L))) ;recursao com o resto da lista
	)
)

;11- Escreva uma função que elimina de uma lista de átomos todas as ocorrências de um dado átomo.
(defun RemoveAtEndLstAt (A L)
	(cond ((atom L) L) ;se L for atomo retorna L
		  ((equal A (car L)) (RemoveAtEndLstAt A (cdr L))); se o primeiro elemento da lista é igual a A
		  ('T (cons (car L) (RemoveAtEndLstAt A (cdr L)))); construi lista nova
	)
)