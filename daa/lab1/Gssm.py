
FM=[None for i in range (3)]

for i in range (3):
	FM[i]=1

PC=[None for i in range (3)]

for i in range (3):
	PC[i]=0

Ho=[-1 for i in range (3)]
Wo=[-1 for i in range (3)]

print("Men pref")
menpref=[[0 for x in range(3)] for y in range(3)] 
menpref=[[0,1,2],
[0,2,1],
[1,2,0]]
"""for i in range(3):
	print("Pref of",i)
	for j in range(3):
		menpref[i][j]=int(input(j))"""

print("Women pref")
womenpref=[[0 for x in range(3)] for y in range(3)] 
for i in range(3):
	print("Pref of",i)
	for j in range(3):
		n=int(input(j))
		womenpref[i][n]=j

flag=1

while flag==1:
	for i in range(3):
		if FM[i]==1:
			flag=1
			break
		else:
			flag=0
	if FM[i]==1 and PC[i]<3:
		if Ho[menpref[i][PC[i]]]==-1:
			Ho[menpref[i][PC[i]]]=i
			Wo[i]=menpref[i][PC[i]]
			PC[i]=PC[i]+1
			FM[i]=0
		elif womenpref[menpref[i][PC[i]]][i]< womenpref[menpref[i][PC[i]]][Ho[menpref[i][PC[i]]]]:
			FM[Ho[menpref[i][PC[i]]]]=1
			Ho[menpref[i][PC[i]]]=i
			Wo[i]=menpref[i][PC[i]]
			PC[i]=PC[i]+1
			FM[i]=0
		else:
			PC[i]=PC[i]+1

for i in range(3):
	print(Ho[i], end=' ')
print()
for i in range(3):
	print(Wo[i], end=' ')






