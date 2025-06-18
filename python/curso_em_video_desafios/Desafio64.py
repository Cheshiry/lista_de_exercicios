i = 0
num = 0

while num != 999:
    print("\033[1;97;26m=-"*30)
    num = int(input("Digite um número inteiro diferente de 999:\n"))
    i += num
print("=-"*30)
print(f"A soma dos números digitados foi : {i-999}")