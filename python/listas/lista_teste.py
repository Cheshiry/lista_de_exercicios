letra = list("python")

print(letra[3])

numeros = [1, 30, 21, 2, 9, 65, 34]
pares = []

for numero in numeros:
    if numero % 2 == 0:
        pares.append(numero)

print(pares)

numeros_02 = [1, 2, 3, 4]
pares_02 = [numero for numero in numeros_02 if numero % 2 == 0]

print(pares_02)

carros =  ("gol") 
print(isinstance(carros, tuple))