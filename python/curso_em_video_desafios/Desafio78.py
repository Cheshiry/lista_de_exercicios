list_num  = []

for listagem in range(0, 5):
    list_num.append(int(input(f"Digite o valor na posição {listagem}: ")))

maior = max(list_num)
menor = min(list_num)

print("-="*30)
print(f"Você digitou os valores {list_num}")
print(f"O maior valor {maior} nas posições ", end = "")
for i, v in enumerate(list_num):
    if v == maior:
        print(f"{i}...", end="")
print()

print(f"O menor valor {menor} nas posições ", end = "")
for i, v in enumerate(list_num):
    if v == menor:
        print(f"{i}..", end="")
print()
print("-="*30)

