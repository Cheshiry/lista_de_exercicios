resp = "S"
sexo = " "
maior_idade = menor_idade_fem = homem = 0


while True:
    idade = int(input("Digite sua idade: "))
    While "MF" not in sexo:
        sexo = str(input("Digite seu sexo[F/M]")).upper().strip().split()[0]
    
       
    if sexo == "F" and idade < 18:
        menor_idade_fem += 1
        
    if sexo == "M":
        homem += 1
        
    if idade >=18:
        maior_idade += 1
        
    while True:
        resp = str(input("Quer continuar cadastrando[S/N]")).upper().strip().split()[0]
    if resp =="S":
        break
    
print("= FIM =")

print(f"""Maiores de 18 anos: {maior_idade}
homens cadastrados: {homem}
Mulheres abaixo dos 18 anos são: {menor_idade_fem}""")
