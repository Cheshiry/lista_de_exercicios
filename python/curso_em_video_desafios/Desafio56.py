somaidade = 0
maioridade = 0
mediaidade = 0
nomevelho = ""
menoridade = 0


for p in range(1, 5):
    print(f"----------{p}° pessoa----------")
    nome = str((input("Nome: "))).strip()
    idade = int((input("idade: ")))
    sexo = str((input("Sexo [M/F]: "))).strip()
    
    somaidade += idade
    
    if p == 1 and sexo in "Mm":
        maioridade = idade
        nomevelho = nome
    
    if sexo in "Mm" and idade > maioridade:
        maioridade = idade
        nomevelho = nome
        
    if sexo in "Ff" and idade < 20:
        menoridade += 1
        
mediaidade = somaidade/ 4

print(f"A media das idade é {mediaidade}.")
print(f"O homem mais velho tem {maioridade} e seu nome é {nomevelho}")
print(f"Tem {menoridade} mulheres com menos de 20 anos.")
