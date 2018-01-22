import java.util.Scanner;

public class page_table{

	public static void main(String args[]){

int i,n,page_size,off,pno;

Scanner inp=new Scanner(System.in);

System.out.println("Enter the no of pages in memory:");

n=inp.nextInt();

int page[]=new int[n];

System.out.println("Enter page size:");

page_size=inp.nextInt();

for(i=0;i<n;i++)

page[i]=-1;

System.out.println("Enter the page table");

System.out.println("\n(Enter frame no as -1 if that page is not present in any frame)");

System.out.println("Page number\tFrame number");

for(i=0;i<n;i++)
{

System.out.print("\n"+(i+1)+"\t\t");

page[i]=inp.nextInt();

}
System.out.println("Enter the logical address(i.e,page no & offset):");

System.out.print("PageNo:");

pno=inp.nextInt();

pno--;

System.out.print("\nOffset:");

off=inp.nextInt();

if(page[pno]==-1)

System.out.println("\nThe required page is not available in any of frames");

else

System.out.println("\nCorresponding physical address: "+(page[pno]*page_size+off));


}
	
}