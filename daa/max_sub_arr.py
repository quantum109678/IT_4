
n=int(input("Enter the number of elements in the array"))
arr=[None for i in range(n)]
for i in range(n):
	arr[i]=int(input())
max_arr=[0 for i in range(n)]
max_arr[0]=1
for i in range(n):
	loc_max=0
	for j in range(0,i):
		if arr[j]<arr[i]:
			if loc_max<max_arr[j]+1:
				loc_max=max_arr[j]+1
				max_arr[i]=loc_max
loc_max=max_arr[0]
for i in range(1,n):
	if loc_max<max_arr[i]:
		loc_max=max_arr[i]

print(loc_max)

