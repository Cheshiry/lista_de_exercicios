soma = numero = index = 0

while True:
    numero = int(input("Digite um número inteiro\n[000 para parar]:\n\t"))

    if numero == 000:
        break
    index += 1
    soma += numero
print(f"A soma dos {index} números digitados foi {soma}!")