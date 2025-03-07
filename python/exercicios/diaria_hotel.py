nome = input("Digite o nome do hospede: ")
dias_no_hotel = int(input("Digite quantos dias o cliente esteve no hotel: "))
custos_estadia = 0.0

if dias_no_hotel > 15:
    custos_estadia = dias_no_hotel * 5.50

elif dias_no_hotel == 15:
    custos_estadia = dias_no_hotel * 6.0

else:
    custos_estadia = dias_no_hotel * 8.0

print(f"O cliente {nome} ficou {dias_no_hotel} no hotel e deve R$ {custos_estadia:.2f}.\n")