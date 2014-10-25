package volkivsky.laba1;

public class laba2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		boolean x = false, y = false, z = true, res = false;
		res = x&!y|z;
		System.out.println(res);
		res = x&(!y|z);
		System.out.println(res);
		res = x|(!(y|z));
		System.out.println(res);
	}

}
