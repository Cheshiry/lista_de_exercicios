primeiro = int(input("1º termo: " ))
razao = int(input("Razão: " ))
decimo = primeiro + (10 - 1) * razao

for lista in range(primeiro, decimo + razao, razao):
    print(lista, end = " → " )
print("Fim")