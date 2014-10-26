package form;

import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.Text;
import org.eclipse.swt.SWT;
import org.eclipse.swt.widgets.Button;
import org.eclipse.swt.widgets.Label;
import org.eclipse.swt.widgets.Group;
import org.eclipse.swt.events.SelectionAdapter;
import org.eclipse.swt.events.SelectionEvent;

public class form {
	private static Text text;
	private static Text text_1;
	private static Text text_2;

	/**
	 * Launch the application.
	 * @param args
	 */
	public static void main(String[] args) {
		Display display = Display.getDefault();
		Shell shell = new Shell();
		shell.setSize(450, 300);
		shell.setText("SWT Application");
		
		Group group = new Group(shell, SWT.NONE);
		group.setText("\u0427\u0430\u0441\u0442\u0438\u043D\u0430 1");
		group.setBounds(10, 10, 180, 154);
		
		text_1 = new Text(group, SWT.BORDER);
		text_1.setBounds(56, 47, 31, 21);
		
		Label lblK = new Label(group, SWT.NONE);
		lblK.setBounds(10, 53, 55, 15);
		lblK.setText("k");
		
		Label label = new Label(group, SWT.NONE);
		label.setBounds(10, 26, 41, 15);
		label.setText("\u0421\u043B\u043E\u0432\u043E");
		
		text = new Text(group, SWT.BORDER);
		text.setBounds(56, 20, 112, 21);
		
		text_2 = new Text(group, SWT.BORDER);
		text_2.setBounds(31, 120, 112, 21);
		
		Button btnNewButton = new Button(group, SWT.NONE);
		btnNewButton.addSelectionListener(new SelectionAdapter() {
			public void widgetSelected(SelectionEvent e) {
				String str = text.getText();
				int k = Integer.parseInt(text_1.getText());
				char[] buf = new char[k];
				str.getChars(0, k, buf, 0);
				text_2.setTextChars(buf);
			}
		});
		btnNewButton.setBounds(10, 79, 158, 25);
		btnNewButton.setText("\u041F\u0435\u0440\u0435\u043D\u0435\u0441\u0442\u0438");
		
		

		shell.open();
		shell.layout();
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) {
				display.sleep();
			}
		}
	}
}
