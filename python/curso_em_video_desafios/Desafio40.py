print("\033[1;96m+=" * 20)

print("Descubra se passou de ano: ")

nome = str(input("Nome: ")).capitalize()

n1 = float(input("Nota 1:"))

n2 = float(input("Nota 2: "))

media = (n1 + n2) / 2

print("*" * 80)

if media > 7:
   print(f"O aluno {nome} foi Aprovado com média {media:.2f}")
   
elif media <=7 and media >=5:
    print(f"O aluno {nome} está em Recuperação com a média {media:.2f}")

else:
    print(f"O aluno {nome} foi Reprovado com média {media:.2f}")
    
