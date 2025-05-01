from math import trunc as parte_inteira, pow as quadrado, sqrt as raiz
from math import sin, cos, tan, radians
from random import choice, shuffle, randrange

""" 
#desafio16

num = float(input("Digite um número com virgula: "))
print(f"O numero {num}\na parte inteira {parte_inteira(num)}\n")


#desafio17
co = float(input("Digite uma medida para o cateto oposto: "))
ca= float(input("Digite outra medida para o cateto adjacente: "))
h = raiz(quadrado(co, 2) + quadrado(ca, 2))
hi = math.hypot(co, ca)#calcula a hiponesa

print(f"A hiponesa é {hi:.2f}")


#desafio18
ang = int(input("Digite o angulo desejado: "))
ang = radians(ang)

seno = sin(ang)
cosseno = cos(ang)
tangente = tan(ang)

print(f"{seno:.2f} seno\n{cosseno:.2f} cosseno\n{tangente:.2f} tangente\n")


#desafio20
n1 = input("Digite o nome do 1º aluno: ")
n2 = input("Digite o nome do 2º aluno: ")
n3 = input("Digite o nome do 3º aluno: ")
n4 = input("Digite o nome do 4º aluno: ")


alunos = [n1, n2, n3, n4]

escolhido = choice(alunos)

print(f"O escolhido foi {escolhido}\ndentre os alunos{alunos[:]}")

"""
#desafio21

n1 = input("Digite o nome do 1º aluno: ")
n2 = input("Digite o nome do 2º aluno: ")
n3 = input("Digite o nome do 3º aluno: ")
n4 = input("Digite o nome do 4º aluno: ")


alunos = [n1, n2, n3, n4]

shuffle(alunos)

print(f"O ordem do sorteio foi {alunos}\n")