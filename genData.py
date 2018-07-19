from random import shuffle 
from secrets import choice, randbelow

# names under 8 characters? am I forgetting an endstring character?
names = ["james", "mary", "john", "lisa", "robert", 
        "linda", "michael","barbra", "william", "helen",
        "david", "sandra", "richard", "maria", "charles",
        "susan", "joseph", "carol", "thomas", "dorothy"]

shuffle(names)
data = [[i+"@email.com", choice([0,1]), randbelow(100000)] for i in names]


import csv

f = open("full_data.csv", "w")

with f:

    writer = csv.writer(f)
    writer.writerows(data)
