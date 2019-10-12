import math


def is_prime(i):
	if i <= 1:
		return False
	if i == 2:
		return True
	j = 2
	while(j <= math.sqrt(i)):
		if i % j == 0:
			return False
		else:
			j += 1
	return True

def gold_con():
	for i in range(4,2001,2):
		for n in range(2,i):
			if is_prime(n):
				if is_prime(i - n):
					print(i,"=",n,"+",i-n)
					break
		if i == n:
			print("error")

def gold_con1():
	prime_arr = [False] * 1999
	for i in range(2,1999):
	 	prime_arr[i] = is_prime(i)

	for i in range(4,2001,2):
		for n in range(2,i):
			if prime_arr[n]:
				if prime_arr[i - n]:
					print(i,"=",n,"+",i-n)
					break
		if i == n:
			print("error")

def gold_con2():
	prime_arr = [0] * 302
	data_arr = [False] * 1999
	index = 0
	for i in range(2,1999):
		if is_prime(i):
			data_arr[i] = True
			prime_arr[index] = i
			index += 1
		else:
			data_arr[i] = False

	for i in range(4,2001,2):
		flag = True
		for j in range(303):
			if prime_arr[j] > i:
				break
			if data_arr[i - prime_arr[j]]:
				flag = False
				print(i,"=",prime_arr[j],"+",i-prime_arr[j])
				break
		if flag:
			print("error")
				

gold_con2()
