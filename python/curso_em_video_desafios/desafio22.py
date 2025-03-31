"""_summary_
Crie um prom que leio o nome e mostre:
-o nome em maiuscula
-o nome em minusculas
-quantas letras tem sem espaços de começo e fim
-quantas letras tem o primeiro nome
"""

nome = input("Digite seu nome completo")

print(nome.upper())
print(nome.lower())
print(nome.strip().capitalize())

nome = nome.split()
first_name = nome[0]

print(len(first_name))
