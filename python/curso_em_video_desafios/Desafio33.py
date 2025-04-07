n1 = int(input("Digite o 1ª número: "))
n2 = int(input("Digite o 2ª número: "))
n3 = int(input("Digite o 3ª número: "))
maior = 0
menor = 0

testar = [n1, n2, n3]
maior = max(testar)
menor = min(testar)

print(f"É o maior {maior}")
print(f"É o menor {menor}")
print(f"{n1} {n2} {n3}")
