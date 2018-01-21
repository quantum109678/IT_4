import java.util.*;

class PageFrame{

	int page_no;

	int frame_no;

	 public PageFrame(int p,int f){

		this.page_no=p;

		this.frame_no=f;
	}
}

public class linkedlist_imp{

	public static void main(String args[]){

		int pn,fn;

		List<PageFrame> list=new LinkedList<PageFrame>();

		Scanner inp=new Scanner(System.in);

		System.out.println("Enter number of pages:");

		int n=inp.nextInt();

		System.out.println("Enter the page size:");

		int page_size=inp.nextInt();

		for(int i=0;i<n;i++){

			System.out.println("Enter the page number:");

			pn=inp.nextInt();

			System.out.println("Enter the corresponding frame number:");

			fn=inp.nextInt();

			PageFrame new_node=new PageFrame(pn,fn);

			list.add(new_node);

		}

		int log_add=13,offset,phy_add,quotient,index;

		System.out.println("Suppose the logical address is "+log_add);

		quo=log_add/page_size;

		offset=log_add%page_size;

	}
}