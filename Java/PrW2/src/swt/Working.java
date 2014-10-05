package swt;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.SWT;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.List;

public class Working {

	protected Shell shell;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			Working window = new Working();
			window.open();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

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
	public void makeIt(boolean x, boolean y) {
		boolean res;
		string result = "";
		res = !(x | y);
			
		res = !x & y;
	
		res = x & !y;
	}
	protected void createContents() {
		shell = new Shell();
		shell.setSize(450, 300);
		shell.setText("SWT Application");
		
		boolean X, Y;
		X = false;
		Y = false;
		
		X = true;
		Y = false;
		
		X = false;
		Y = true;
						
		
		
		
		
		
		Button btnNewButton = new Button(shell, SWT.NONE);
		btnNewButton.addSelectionListener(new SelectionAdapter() {
			
			@Override
			public void widgetSelected(SelectionEvent e) {
				
			}
		});
		btnNewButton.setBounds(4, 125, 75, 25);
		btnNewButton.setText("\u0412\u0430\u0440\u0456\u0430\u043D\u0442 1");
		
		Button btnNewButton_1 = new Button(shell, SWT.NONE);
		btnNewButton_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
			}
		});
		btnNewButton_1.setBounds(4, 156, 75, 25);
		btnNewButton_1.setText("\u0412\u0430\u0440\u0456\u0430\u043D\u0442 2");
		
		Button button = new Button(shell, SWT.NONE);
		button.setBounds(4, 187, 75, 25);
		button.setText("\u0412\u0430\u0440\u0456\u0430\u043D 3");
		
		List list = new List(shell, SWT.BORDER);
		list.setBounds(4, 10, 71, 102);

	}

}
