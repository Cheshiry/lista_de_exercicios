thisdict = {
    "brand": "Ford",
    "model": "Mustang",
    "year": 1964
}

print(thisdict)
print(thisdict["model"])
print(len(thisdict))
print(type(thisdict))

dicionary = dict(name = "John", age = 36, country = "Norway")
print(dicionary)

car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}

x = car.keys()

print(x) #before the change

car["color"] = "white"

print(x) #after the change