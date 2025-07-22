produtos = ("ração", 190,
            "Areia", 20,
            "Comedouro", 10,
            "Bebedouro",10,
            "Sachê",8)
i = 0

print(f"{'Loja DaVilla':^40}")
print("-"*40)
print(f"{'Listgem de preços':^40}")
print("-"*40)

for item in range(0,len(produtos)):
    if item % 2 == 0:
        print(f"{produtos[item]:.<30}" , end="")
    else:
        print(f"R${produtos[item]:>7.2f}")

print("-"*40)
