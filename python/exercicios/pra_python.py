age = int(input("Qual a sua idade? \n"))
name = input("Qual o seu nome?\n")
age_100 = 2025 - age + 100

print(f"""{name.title()}, sua idade hoje é {age}.
E vocÊ fará 100 anos, no ano {age_100}""")

import datetime
user = str(input("What's your name? "))
age = int(input("How old are you? "))

print("Hi " +user+ ". You will be 100 years old in " + str(datetime.datetime. today().year - age + 100)+ "!")
