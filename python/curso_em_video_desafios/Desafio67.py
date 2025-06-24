num = i = 0

while True:
    i = 0
    num = int(input("Digite um número para ver sua tabuada: "))
    print("-+"*50)
    if num < 0:
        break
    for tabuada in range(0,11):
        print(f"{num} X {i:2} = {num*i:2}")
        i += 1
    print("-+"*50)
print("FIM")