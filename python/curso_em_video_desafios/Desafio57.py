gen = str(input("Digite [F/M]: ")).upper().strip()[0]

while gen not in "FfMm":
    
    gen = str(input("Dados inválido, por favor informe seu sexo: ")).upper().strip()[0]
    
print("Gênero {gen} informados com sucesso!")
