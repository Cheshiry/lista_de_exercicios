numero = ("zero", "one", "two", "three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twelve")
resposta = "s"

num = int(input("Digite um número: "))
while True:
    if 0 <= num <=20:
        print(numero[num])
    
    else:
        num = int(input("Digite um número valido entre (0 e 20): "))
    
    print(numero[num])
    
    resposta = str(input("Gostaria de continuar digitando? ")).lower().strip().split()[0]

    
