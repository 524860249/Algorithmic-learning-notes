
def ein_ladder():
	n = 1
	while(not (n % 2 == 1 and n % 3 == 2 and n % 5 == 4 and n % 6 == 5 and n % 7 == 0)):
		n += 1
	return n

ein_ladder()

def ein_ladder1():
	n = 7
	while(not(n % 2 == 1 and n % 3 == 2 and n % 5 == 4 and n % 6 == 5 and n % 7 == 0)):
		n += 7
	return n

ein_ladder1()

def ein_ladder2():
	com_mul = 6
	while(not(com_mul % 5 ==0)):
		com_mul += 6;
	
	result = 29
	while(not(result % 7 == 0)):
		result += com_mul;
	return result

ein_ladder2()