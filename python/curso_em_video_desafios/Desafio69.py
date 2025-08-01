maior_idade = menor_idade_fem = homem = idade = 0
while True:
    idade = int(input("Digite sua idade: "))
    sexo = " "
    while sexo not in "MF":
        sexo = str(input("Digite seu sexo[F/M]")).upper().strip()[0]
    resp = " "
    if sexo == "F" and idade < 18:
        menor_idade_fem += 1
    if sexo == "M":
        homem += 1
    if idade >=18:
        maior_idade += 1
    while resp not in "SN":
        print("-"*50)
        resp = str(input("Quer continuar cadastrando[S/N]")).upper().strip().split()[0]
    print("-"*50)
    if resp ==  "N":
        break    
print("= FIM =")
print(f"""
Maiores de 18 anos: {maior_idade}
homens cadastrados: {homem}
Mulheres abaixo dos 18 anos são: {menor_idade_fem}
""")
