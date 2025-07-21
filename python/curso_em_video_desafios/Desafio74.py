from random import randint

num = (randint(1,10),randint(1,10),randint(1,10),randint(1,10),randint(1,10),randint(1,10))

print("Os valores sorteados foram: ", end = " ")

for n in num:
    print(f"{n}", end=" ")

print('\n')
print(f"O maior número foi: {max(num)}")
print(f"O menor número foi: {min(num)}")

'''
for list in range(0,6):
    entrada = (randint(0,10))
    num.append(entrada)
'''

