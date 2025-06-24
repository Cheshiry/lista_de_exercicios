quant = num = soma = media = menor = maior= 0
resp = "S"

while resp in "Ss":
    print("\033[1;97;26m=-"*30)
    num = int(input("Digite um número:\n"))
    quant += 1
    soma += num
    if quant == 1:
        menor = maior = num
    else:
        if num > maior:
            maior = num
        if num < menor:
            menor = num

    print("=-"*30)
    resp = str(input("Gostaria de continuar somando[s/n]\n")).upper().strip()[0]
    media = (soma)/(quant)

print("=-"*30)
print(f"A media dos números digitados foi : {media:.2f}")
print(f"O menor: {menor}")
print(f"O maior: {maior}")
print(f"E foram digitados: {quant} numeros")
print("=-"*30)
    