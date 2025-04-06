"""_summary_
Crie um prom que leio o nome e mostre:
se ela tem com "Silva" no nome
"""

nome = str(input("Digite o seu nome: ")).strip().upper()

nome = nome.split()

print(nome[1] == "SILVA")
