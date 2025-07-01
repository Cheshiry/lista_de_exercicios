resp = "S"
sexo = " "
maior_idade = menor_idade_fem = homem = idade = 0


while True:
    while sexo not in "MF":
        idade = int(input("Digite sua idade: "))
        sexo = str(input("Digite seu sexo[F/M]")).upper().strip().split()[0]
       
    if sexo == "F" and idade < 18:
        menor_idade_fem += 1
        
    if sexo == "M":
        homem += 1
        
    if idade >=18:
        maior_idade += 1
        
    resp = str(input("Quer continuar cadastrando[S/N]")).upper().strip().split()[0]
    if resp ==  "N":
        break
    
print("= FIM =")

print(f"""Maiores de 18 anos: {maior_idade}
homens cadastrados: {homem}
Mulheres abaixo dos 18 anos são: {menor_idade_fem}""")
