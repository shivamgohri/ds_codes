filename = "input.txt"

# filename = input()
t = open(filename, 'rt')

lines = t.readlines()

count = 0
ans = 0

for line in lines:
	words = line.split(' ')
	print(words[-1])
	# if curr > 5000:
	# 	count += 1
	# 	ans += curr
	

myfile = open( "bytes_"+filename, 'w+')

myfile.write("%d\n" %count)
myfile.write("%d" %ans)