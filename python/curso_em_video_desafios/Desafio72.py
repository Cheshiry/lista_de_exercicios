numero = ("zero", "one", "two", "three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twelve")

num = int(input("Digite um número: "))
while True:
    if num >=0 and num <=20:
        print(numero[num])
        break
    
    else:
            num = int(input("Digite um número valido entre (0 e 20): "))


    
