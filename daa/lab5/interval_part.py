class Node:

	def __init__(self,val):

		self.key=val
		self.next=None

class Job:

	def __init__(self,t1,t2):
		self.st_t=t1
		self.end_t=t2

L=[]
In=[]

n=int(input("Enter number of intervals:"))

print("Enter the intervals:")

for i in range(0,n):
	t1,t2=input().split()
	t1,t2=int(t1),int(t2)
	temp=Job(t1,t2)
	In.append(temp)

for i in range(0,n-1):

 	for j in range(i+1,n):

 		if In[i].st_t>In[j].st_t:

 			temp1=In[i].st_t
 			temp2=In[i].end_t

 			In[i].st_t=In[j].st_t
 			In[i].end_t=In[j].end_t

 			In[j].st_t=temp1
 			In[j].end_t=temp2

L.append(Node(0))

for i in range(1,n):

 	flag=0

 	for j in range(0,len(L)):

 		curr=L[j]

 		while curr.next!=None:

 			curr=curr.next

 		if In[i].st_t>In[curr.key].end_t:

 			curr.next=Node(i)

 			flag=1

 			break

 	if flag==0:

 		L.append(Node(i))


for i in range(0,len(L)):

	print("Resource ",i+1)

	curr=L[i]

	while curr!=None:

		print(In[curr.key].st_t,In[curr.key].end_t,end=' ')

		curr=curr.next

	print()





