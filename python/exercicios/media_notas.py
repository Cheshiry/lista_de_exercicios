nome = input("Qual o nome do aluno: \n")
notas1 = float((input("Nota 1: \n")))
notas2 = float((input("Nota 2: \n")))
notas3 = float((input("Nota 3: \n")))
media = (notas1 + notas2 + notas3)/3

print(media.__round__(2))

if media >= 7:
    print("Aprovado!")

elif (media < 6 or media > 4):
    print("Recuperação")

else:
    print("Reprovado!")