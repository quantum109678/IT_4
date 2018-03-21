class activity:

	def __init__(self,n1,n2):
		self.st=n1
		self.et=n2
		self.visited=0

count=1
def schedule(arr,n):

	global count

	i=0;

	print("Resource ",count);

	print(arr[i].st,arr[i].et);

	for j in range(1,n):

		if arr[j].visited!=1:

			if arr[j].st>arr[i].et:

				print(arr[j].st,arr[j].et)

				i=j

				arr[j].visited=1
	count=count+1


L=[]

def main():
	n=int(input("Enter number of intervals:"))
	for i in range(0,n):
		v1,v2=input().split()
		v1,v2=int(v1),int(v2)
		L.append(v1,v2)
	while len(L)!=0:
		schedule(L,len(l))


if __name__ == '__main__':
	main()