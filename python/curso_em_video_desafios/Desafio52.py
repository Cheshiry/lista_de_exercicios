num = int(input("Digite um número: "))
i = 0

for a in range(1, num + 1):
    if num % a  == 0:
        print("\033[33m", end = " ")
        i += 1
    else:
        print("\033[36m", end = " ")
    print(f"{a}", end = " ")

print(f"\n\033[mO número {num} foi divisivel {i} vezes.")

if i == 2:
    print(f"E por isso é PRIMO")
else:
    print(f"E por isso ele NÃO É PRIMO")
