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
n=input(int("Enter number of intervals:")



	