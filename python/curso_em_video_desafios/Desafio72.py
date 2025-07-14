numero = ("zero", "one", "two", "three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twelve")
resposta = "s"

while True:
    num = int(input("Digite um número: "))
    if resposta == "s":
        if 0 <= num <=20:
            print(numero[num])
            resposta = str(input("Gostaria de continuar digitando? ")).lower().strip().split()[0]
        else:
            while 0 < num >20:
                num = int(input("Digite um número valido entre (0 e 20): "))
    else:
        break


    
