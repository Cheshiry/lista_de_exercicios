print("Sequência de Fibonacci")
print("-"*50)

contador = int(input("Digite um número: "))
i = 3
t1 = 0
t2 = 1
print(f"{t1} > {t2} > ", end="")

while i <= contador:
    t3 = t1 + t2
    print(t3, end=" > ")
    t1 = t2
    t2 = t3
    i += 1
print("Fim")

print("=+"*20)
