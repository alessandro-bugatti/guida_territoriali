#crea un input per mozzarelle

import random

N = input("")
print N
for i in range(int(N)):
	print str(random.randrange(10000000)) + " " + str(random.randrange(10000000))
