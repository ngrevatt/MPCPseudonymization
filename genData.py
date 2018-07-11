from random import shuffle 
from secrets import choice, randbelow

names = ["james", "mary", "john", "patricia", "robert", 
        "linda", "michael","barbra", "william", "elizabeth",
        "david", "jennifer", "richard", "maria", "charles",
        "susan", "joseph", "margaret", "thomas", "dorothy"]

shuffle(names)
data = [[i+"@email.com", choice([0,1]), randbelow(100000)] for i in names]


import csv

f = open("full_data.csv", "w")

with f:

    writer = csv.writer(f)
    writer.writerows(data)
