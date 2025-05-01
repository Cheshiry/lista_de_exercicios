#Desafio 48
soma = 0
contador = 0

for num in range(1, 501, 2):
    if num % 3 == 0:
        contador += 1 
        soma += num
print(f"A soma de todos os {contador} valores solicitados foi {soma}")