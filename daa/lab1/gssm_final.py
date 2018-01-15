inp_file=open("input.txt",'r')
lines=inp_file.readlines()
n=len(lines[0].split())
print(n)
men={}
women={}
m=lines[0].split()
w=lines[1].split()
for i in range(len(m)):
	men[m[i]]=i
for i in range(len(w)):
	women[w[i]]=i


FM=[1 for i in range (n)]

PC=[0 for i in range (n)]


Ho=[-1 for i in range (n)]
Wo=[-1 for i in range (n)]

menpref=[[0 for x in range(n)] for y in range(n)] 
for i in range(0,n):
	for j in range(0,n):
		mpre=lines[i+2].split()
		menpref[i][j]=women[mpre[j+1]]

womenpref=[[0 for x in range(5)] for y in range(5)] 
for i in range(n):
	for j in range(n):
		wpre=lines[i+7].split()
		cur=men[wpre[j+1]]
		womenpref[i][cur]=j

flag=1

while flag==1:
	for i in range(n):
		if FM[i]==1:
			flag=1
			break
		else:
			flag=0
	if FM[i]==1 and PC[i]<n:
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

for i in range(n):
	print(m[i],w[Wo[i]])






