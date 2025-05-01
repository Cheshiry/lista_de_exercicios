mult = int(input("Escolha um número para fazer sua tabuada: "))

print("*" * 50)

for num in range(0, 11):
    print(f"{mult} X {num:2} =  {mult*num:2}")

print("*" * 50)