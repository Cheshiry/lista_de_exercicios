"""_summary_
Crie um prom que leio o nome e mostre o 1º nome e o ultimo separados:

Ex: Ana Maria de Souza
primeiro: Ana
Último: Souza
"""

nome = str(input("Digite o seu nome: \n"))

nome = nome.split()

primeiro_nome = nome[0]
sobrenome = nome[-1]

print(f"O primeiro nome é: {primeiro_nome} ")
print(f"O sobrenome é: {sobrenome}")
