list = []
resp = "s"
listnum = 0

while True:
    if resp == "s":
        listnum = int(input("Digite um numero: "))

        if listnum in list:
            print("Você já digitou esse numero!")
            
        else:
            list.append(listnum)

        resp = str(input("Gostaria de cotinuar digitando?[s/n] ")).lower().split()[0]
    elif resp == "n":
        break
print(list)