i = num = soma = media = menor = maior= 0
resp = "S"

while resp != "N":
    print("\033[1;97;26m=-"*30)
    num = int(input("Digite um número:\n"))
    if menor == 0:
        menor = num
    elif num <= menor:
        menor = num
    elif num > maior:
        maior = num
    i += 1
    soma += num
    print("=-"*30)
    resp = str(input("Gostaria de continuar somando[s/n]")).upper().strip()
    media = (soma)/(i)

print("=-"*30)
print(f"A media dos números digitados foi : {media:.2f}")
print(f"O menor: {menor}")
print(f"O maior: {maior}")
print(f"E foram digitados: {i} numeros")
print("=-"*30)
    