import java.util.Scanner;

public class page_table{

	public static void main(String args[]){

int page[MAX],i,n,f,ps,off,pno;

Scanner inp=new Scanner(System.in);

System.out.println("Enter the no of pages in memory");

n=inp.nextInt();

System.out.println("\nEnter page size");

ps=inp.nextInt();

System.out.println("\nEnter no of frames");

f=inp.nextInt();

for(i=0;i<n;i++)
page[i]=-1;
System.out.println("\nEnter the page table\n");

System.out.println("(Enter frame no as -1 if that page is not present in any frame)\n\n");

System.out.println("\npageno\tframeno\n-------\t-------");

for(i=0;i<n;i++)
{

System.out.println(i);

page[i]=inp.nextInt();

}
System.out.println("\n\nEnter the logical address(i.e,page no & offset):");

pno=inp.nextInt();

off=inp.nextInt();

if(page[pno]==-1)

System.out.println("\n\nThe required page is not available in any of frames");

else

System.out.println("\n\nPhysical address(i.e,frame no & offset):"+page[pno]+off);


}
	}
}