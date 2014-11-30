package laba3;

import java.text.DecimalFormat;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class laba3z1 {

	protected Shell shell;
	private Text text;
	private Text text_1;
	private Text text_2;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			laba3z1 window = new laba3z1();
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
	protected void createContents() {
		shell = new Shell();
		shell.setSize(326, 125);
		shell.setText("SWT Application");
		
		Label lblNewLabel = new Label(shell, SWT.NONE);
		lblNewLabel.setBounds(10, 10, 11, 15);
		lblNewLabel.setText("x");
		
		text = new Text(shell, SWT.BORDER);
		text.setBounds(27, 4, 76, 21);
		
		text_1 = new Text(shell, SWT.BORDER);
		text_1.setBounds(128, 4, 76, 21);
		
		Label lblY = new Label(shell, SWT.NONE);
		lblY.setText("y");
		lblY.setBounds(111, 10, 11, 15);
		
		text_2 = new Text(shell, SWT.BORDER);
		text_2.setBounds(227, 4, 76, 21);
		
		Label lblZ = new Label(shell, SWT.NONE);
		lblZ.setText("z");
		lblZ.setBounds(210, 10, 11, 15);
		
		Label lblA = new Label(shell, SWT.NONE);
		lblA.setBounds(10, 31, 21, 15);
		lblA.setText("a=");
		
		Label lblB = new Label(shell, SWT.NONE);
		lblB.setBounds(159, 31, 21, 15);
		lblB.setText("b=");
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(37, 31, 108, 15);
		
		Label label_1 = new Label(shell, SWT.NONE);
		label_1.setBounds(179, 31, 124, 15);
		
		Button button = new Button(shell, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				calculate(Double.parseDouble(text.getText()), Double.parseDouble(text_1.getText()), Double.parseDouble(text_2.getText()));
			}
			
			public void calculate(double x, double y, double z)
			{
				double a, b;
				DecimalFormat df = new DecimalFormat("#.#####");
				//a=((Math.sqrt(Math.abs(x-1))-Math.pow(y, 1/3))/(1+(Math.pow(x, 2)/2)+(Math.pow(y, 2)/4)));
				//b=(x*(Math.atan(z)+(1/Math.exp(x+3))));
				a=(y+(x/(Math.pow(y, 2)+Math.abs(Math.pow(x, 2)/(y+Math.pow(x, 3)/3)))));
				b=(1+Math.pow(Math.tan(z/2), 2));
				label.setText(df.format(a));
				label_1.setText(df.format(b));
			}
		});
		
		button.setBounds(10, 55, 75, 25);
		button.setText("\u0420\u0430\u0445\u0443\u0432\u0430\u0442\u0438");

	}
}
