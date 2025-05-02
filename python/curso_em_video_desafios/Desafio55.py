maior = 0
menor = 0

for p in range(1, 6):
    peso = float(input(f"Peso da {p}º pessoa: "))
    if p == 1:
        menor = peso
        menor = peso
    else:
        if peso > maior:
            maior = peso  
        elif peso < menor:
            menor = peso

print(f"O maior peso lido {maior:.2f}Kg")
print(f"O menor peso lido {menor:.2f}Kg")