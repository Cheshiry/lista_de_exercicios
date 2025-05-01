result = 0

for num in range(0, 3):
    par = int(input("Digite um número: "))
    if par % 2 == 0:
        result += par
        
print(result)
