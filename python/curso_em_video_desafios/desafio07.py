n1 = float(input("Digite a 1ª nota do aluno: "))
n2 = float(input("Digite a 2ª nota do aluno: "))

media = (n1+n2)/2

if media >= 7:
    print(f"O aluno teve media {media:.2f}, e está aprovado!\n")
elif media < 7 and media >=5:
    print(f"O aluno teve media {media:.2f}, recuperação\n")
else:
    print(f"O aluno teve media {media:.2f}, reprovado!\n")