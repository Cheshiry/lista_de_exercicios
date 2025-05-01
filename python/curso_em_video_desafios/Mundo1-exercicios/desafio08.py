medida_metros = float(input("Digite uma distância em metros: "))

medida_km = medida_metros / 1000
medida_hm = medida_metros / 100
medida_dam = medida_metros / 10
medida_dm = medida_metros * 10
medida_cm = medida_metros * 100
medida_mm = medida_metros * 1000

print(f"{medida_km}km")
print(f"{medida_hm}hm")
print(f"{medida_dam}dam")
print(f"{medida_dm}dm")
print(f"{medida_cm}cm")
print(f"{medida_mm}mm")

#Outro jeito

print(f"{medida_metros / 1000}km")
print(f"{medida_metros / 100}hm")
print(f"{medida_metros / 10}dam")
print(f"{medida_metros * 10}dm")
print(f"{medida_metros* 100}cm")
print(f"{medida_metros * 1000}mm")