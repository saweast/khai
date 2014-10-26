package laba4;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.events.KeyAdapter;
import org.eclipse.swt.events.KeyEvent;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class laba4z1 {

	protected Shell shell;
	private Text text;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			laba4z1 window = new laba4z1();
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
		shell.setSize(450, 167);
		shell.setText("SWT Application");
		
		Label label = new Label(shell, SWT.NONE);
		label.setBounds(10, 10, 80, 15);
		label.setText("\u0412\u0432\u0435\u0434\u0456\u0442\u044C \u0441\u043B\u043E\u0432\u043E:");
		
		Label label_1 = new Label(shell, SWT.NONE);
		label_1.setBounds(181, 10, 243, 46);
		
		text = new Text(shell, SWT.BORDER);
		text.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e)
			{
				if( Character.isWhitespace(e.character) ) e.doit=false;
				else e.doit=true;
			}
		});
		text.setBounds(94, 7, 76, 21);
		
		Button button = new Button(shell, SWT.NONE);
		button.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e)
			{
				if(text.getText().length()>=4)
				label_1.setText(Boolean.toString(text.getText().substring(1, 2).equals(text.getText().substring(3, 4))));
				else label_1.setText("–€док менший, н≥ж потр≥бно.\n¬вед≥ть м≥н≥мум 4 символи!");
			}
		});
		button.setBounds(10, 31, 75, 25);
		button.setText("\u0417\u0430\u0432\u0434\u0430\u043D\u043D\u044F 1");
		
		Label label_2 = new Label(shell, SWT.NONE);
		label_2.setBounds(181, 62, 243, 46);
		
		Button button_1 = new Button(shell, SWT.NONE);
		button_1.addSelectionListener(new SelectionAdapter() {
			@Override
			public void widgetSelected(SelectionEvent e)
			{
				int i=0,j=0;
				for(i=0;i<text.getText().length();i++)
				{
					for(j=i+1;j<text.getText().length();j++)
					{
						if(text.getText().substring(i,i+1).equals(text.getText().substring(j,j+1)))
						{
							label_2.setText(text.getText().substring(i,i+1));
							return;
						}
					}
				}
			}
		});
		button_1.setText("\u0417\u0430\u0432\u0434\u0430\u043D\u043D\u044F 2");
		button_1.setBounds(10, 83, 75, 25);

	}
}
