numeros = { 1, 2, 2, 3, 3, 4, 4, 5}
carro = {"gol","palio","ka","ford","fusca","ka","ka",}
#numeros = list(numeros)
print(numeros)

for num in numeros:
    print(num)

for indice, num in enumerate(numeros):
    print(f"{indice}:{num}")

numeros.discard(22)