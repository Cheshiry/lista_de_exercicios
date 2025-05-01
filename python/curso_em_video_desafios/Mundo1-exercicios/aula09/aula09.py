frase = "Curso em Video de Python 2025"
frase2 = "       Curso Python 2025                 "

print(frase[9:21:2])
print(frase[::2])
print(frase[:9:2])
print(len(frase))
print(frase.count("o",0,29))
print(frase.find("deo"))
print(frase.replace("Python","Android"))

print(frase.upper())
print(frase.lower())
print(frase.capitalize())
print(frase.title())


print(frase2)
print(frase2.strip)
print(frase2.rstrip())
print(frase2.lstrip())
print(frase2.lstrip())

#print(frase.split())
print("-".join(frase))


print(frase.upper().count('O'))
print(frase.lower().find('video'))
print(frase2.strip().upper())
print("Curso" in frase)

div = frase.split()
print(div[0][2])
