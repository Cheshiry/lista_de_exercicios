somaidade = 0
maioridade = 0
mediaidade = 0
nomevelho = ""

for p in range(1, 5):
    print(f"{p}° pessoa")
    nome = str((input("Nome: "))).strip()
    idade = int((input("idade: ")))
    sexo = str((input("Sexo [M/F]: "))).strip()
    print("*" * 40)
    somaidade += idade
    
    if p == 1 and sexo in "Mm":
        maioridade = idade
        nomevelho = nome
    if sexo == "Mm" and idade > maioridade:
        maioridade = idade
        nomevelho = nome
        
mediaidade = somaidade/ 4

print(f"A media das idade é {mediaidade}.")
print(f"O homem mais velho tem {maioridade} e seu nome é {nomevelho}")
