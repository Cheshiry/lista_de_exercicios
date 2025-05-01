result = 0
i = 0
npar = 0

for num in range(0, 6):
    par = int(input("Digite um número: "))
    if par % 2 == 0:
        result += par

        npar += 1
    i += 1
        
print(f"Dos {i} numeros digitados a soma dos {npar} numeros pares foi {result}")
