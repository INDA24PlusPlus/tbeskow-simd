import random
import string

amount = 10000

with open('in.txt', 'w') as f:
    f.write(f"{amount}\n")
    for i in range(amount):
        length = random.randint(1, 100000)
        f.write("".join(random.choices(string.ascii_lowercase, k=length)) + "\n")
