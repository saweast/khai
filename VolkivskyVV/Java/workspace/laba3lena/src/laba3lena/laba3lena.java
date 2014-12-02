package laba3lena;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;
import org.eclipse.swt.widgets.Label;

public class laba3lena {

	protected Shell shell;
	private Text text;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			laba3lena window = new laba3lena();
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
		shell.setSize(261, 142);
		shell.setText("SWT Application");
		
		Label lblResult = new Label(shell, SWT.NONE);
		lblResult.setBounds(10, 76, 55, 15);
		lblResult.setText("result");
		
		text = new Text(shell, SWT.BORDER);
		text.setBounds(10, 10, 76, 21);
		
		Button btnCount = new Button(shell, SWT.NONE);
		btnCount.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e) {
				float summ = 0, sdl=0;
				float n = Float.parseFloat(text.getText().toString());
				for(int i=1;i<n;i++)
				{
					for(int j=2;j<n+1;j++)
					{
						sdl+=1/j;
					}
					summ+=factorial(n)/sdl;
				}
				lblResult.setText(Float.toString(summ));
			}
		    public float factorial(float n)
		    {
		        if (n == 0) return 1;
		        return n * factorial(n-1);
		    }
		});
		btnCount.setBounds(10, 45, 75, 25);
		btnCount.setText("Count");
	}
}
