package laba2W;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.List;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Label;

public class form1 {

	protected Shell shell;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			form1 window = new form1();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	static String makeIt(boolean x, boolean y){
		boolean res;
		String result="";
		res = !(x | y);
		result+="!(X|Y) = " + res;
		res = !x & y;
		result+="\n!X&Y = " + res;
		res = x & !y;
		result+="\nX&!Y = " + res;	
		return result;
	}
	
	boolean X, Y;

	/**
	 * Open the window.
	 */
	public void open() {
		Display display = Display.getDefault();
		createContents();
		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}

	/**
	 * Create contents of the window.
	 */
	protected void createContents() {
		shell = new Shell();
		shell.setSize(200, 200);
		shell.setText("SWT Application");
		
		Label label0 = new Label(shell, SWT.NONE);
		label0.setBounds(10, 10, 214, 68);
		
		Button button1 = new Button(shell, SWT.NONE);
		button1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				X = true;
				Y = true;
				label0.setText(makeIt(X, Y));				
			}
		});
		button1.setBounds(10, 84, 75, 25);
		button1.setText("true true");
		
		Button button2 = new Button(shell, SWT.NONE);
		button2.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				X = false;
				Y = false;
				label0.setText(makeIt(X, Y));
			}
		});
		button2.setBounds(91, 84, 75, 25);
		button2.setText("false false");
		
		Button button3 = new Button(shell, SWT.NONE);
		button3.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				X = true;
				Y = false;
				label0.setText(makeIt(X, Y));
			}
		});
		button3.setText("true false");
		button3.setBounds(10, 115, 75, 25);
		
		Button button4 = new Button(shell, SWT.NONE);
		button4.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				X = false;
				Y = true;
				label0.setText(makeIt(X, Y));
			}
		});
		button4.setText("false true");
		button4.setBounds(91, 115, 75, 25);
		
		

	}
}
