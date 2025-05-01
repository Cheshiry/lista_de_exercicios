a = int(input("Digite o 1ª número: "))
b = int(input("Digite o 2ª número: "))
c = int(input("Digite o 3ª número: "))
maior = 0
menor = 0
""" 
testar = [a, b, c]
maior = max(testar)
menor = min(testar) 
"""

menor = a

if b > a and b < c:
    menor = b
if c < a and c < b:
    menor = c

if b > a and b > c:
    maior = b

if c > a and c > b:
    maior = c

print(f"É o maior {maior}")
print(f"É o menor {menor}")
print(f"{a} {b} {c}")
