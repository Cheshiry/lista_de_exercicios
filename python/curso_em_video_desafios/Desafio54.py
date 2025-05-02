from datetime import date

i_maior = 0
i_menor = 0

for amigos in range(1, 8):
    anonasc = int(input(f"O ano de nascimento da {amigos}º pessoa: "))
    
    anoatual = date.today().year
    idade = anoatual - anonasc
    
    if idade >=  21:    
        i_maior += 1
    else:
        i_menor += 1
        
print(f"São {i_maior} maior de idade \n{i_menor} menor de idade.")
