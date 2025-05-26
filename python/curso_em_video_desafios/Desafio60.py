num = int(input("Digite um número: "))
from math import factorial as fatorial

i = num 
fac = fatorial(num)
f = 1

print(f"Calculando {num}! = ", end="")

for a in range(num,0,-1):
    print(i, end=" ")
    print("X" if i > 1 else "=", end=" ")
    f *= i
    i-=1
    
print(f)

'''
while i > 0:
    
    print(i, end=" ")
    print("X" if i > 1 else "=", end=" ")
    f *= i
    i-=1
    
print(f)
'''
