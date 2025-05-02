num = int(input("Digite um número para verificar se é primo:"))

for a in range(1, 20):
    if num % 1 == 0 or num % num == 0:
        print(num, "primo")
