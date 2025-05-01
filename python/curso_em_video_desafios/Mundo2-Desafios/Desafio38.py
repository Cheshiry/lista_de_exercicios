print("\033[1;35m=+"*20)

num1 = int(input("Digite um número para comparar: "))
num2 = int(input("Digite outro número para comparar: "))

print("=+"*20)

if num1 > num2:
    print(f"O maior é {num1} e o menor {num2}")
elif num1 == num2:
    print(f"Os números {num1} e {num2} são iguais. ")
else:
    print(f"O maior é {num2} e o menor {num1}")

print("=+"*20)
