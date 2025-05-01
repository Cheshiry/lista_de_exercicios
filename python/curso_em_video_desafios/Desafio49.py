mult = int(input("Escolha um número para fazer sua tabuada: "))

for num in range(0, 11):
    result = mult * num
    print(f"{mult} X {num:2} =  {result:2}")
