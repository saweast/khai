package volkivsky.laba1;
public class vadim2 {
	public static void main(String[] args) {
			boolean X, Y;
			X = true;
			Y = true;
			makeIt(X, Y);
			X = false;
			Y = false;
			makeIt(X, Y);
			X = true;
			Y = false;
			makeIt(X, Y);
			X = false;
			Y = true;
			makeIt(X, Y);				
	}
	static void makeIt(boolean x, boolean y){
		boolean res;
		res = !(x | y);
		System.out.println("X: " + x + " Y: " + y + " = " + res);
		res = !x & y;
		System.out.println("X: " + x + " Y: " + y + " = " + res);
		res = x & !y;
		System.out.println("X: " + x + " Y: " + y + " = " + res + "\n");	
	}
}
