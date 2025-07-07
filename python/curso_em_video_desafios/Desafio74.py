import random

num = []

for list in range(0,6):
    entrada = (random.randint(0,10))
    num.append(entrada)

maior = max(num)
menor = min(num)
num_tuple = num
print(num_tuple)

print(f"O maior número foi: {maior}")
print(f"O menor número foi: {menor}")

