import heapq

class code:

	def __init__(self,s,f):
		self.sym=s
		self.freq=f

class Node:

	def __init__(self,s,f,lc,rc):
		self.symb=s
		self.fre=f
		self.left=lc
		self.right=rc
		self.encode=[]

	def __lt__(self,other):

		return self.fre<other.fre
H=[]
def Huffman(L):
	n=len(L)
	leaves=[]
	for i in range(n):
		l=Node(L[i].sym,L[i].freq,None,None)
		leaves.append(l)
	for i in range(n):
		heapq.heappush(H,leaves[i])
	for i in range(n-1):
		min1=heapq.heappop(H)
		min2=heapq.heappop(H)
		#print(min1.symb,min2.symb)
		new_node=Node(-1,min1.fre+min2.fre,min2,min1)
		heapq.heappush(H,new_node)
	return heapq.heappop(H)

def print_code(H,root,arr,top):
	if root==None:
		return

	if root.left==None and root.right==None and root.symb!=-1:
		print(root.symb,":",end=' ')
		for i in range(top):
			print(arr[i],end='')
		print()
		

	if root.left!=None:
		arr[top]=0
		print_code(H,root.left,arr,top+1)

	if root.right!=None:
		arr[top]=1
		print_code(H,root.right,arr,top+1)





n=int(input("Enter number of symbols:"))
L=[]
print("Enter symbols and their corresponding frequencies:")
for i in range(n):
	s,f=input().split()
	f=int(f)
	m=code(s,f)
	L.append(m)
root=Huffman(L)
arr=[None for i in range(n)]
top=0
print_code(H,root,arr,top)

