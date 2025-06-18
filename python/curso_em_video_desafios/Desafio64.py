soma = i = 0


num = int(input("Digite um número inteiro diferente de 999:\n"))

while num != 999:
    print("\033[1;97;26m=-"*30)
    soma += num
    i+=1
    num = int(input("Digite um número inteiro diferente de 999:\n"))

print("=-"*30)
print(f"a soma dos {i} números digitados foi {soma}")
